#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

// Define a 3D point for storing atom coordinates
struct Point3D {
    double x, y, z;

    // Overload subtraction operator for vector operations
    Point3D operator-(const Point3D& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    // Overload division operator for scalar division
    Point3D operator/(double scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    // Overload multiplication operator for scalar multiplication
    Point3D operator*(double scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }
};

// Compute the dot product of two vectors
double dot(const Point3D& a, const Point3D& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Compute the cross product of two vectors
Point3D cross(const Point3D& a, const Point3D& b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

// Compute the magnitude of a vector
double magnitude(const Point3D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Normalize a vector
Point3D normalize(const Point3D& v) {
    double mag = magnitude(v);
    return v / mag;
}

// Parse Cα atom coordinates from a PDB file
std::vector<std::vector<Point3D>> parse_ca_atoms(const std::string& pdb_file) {
    std::ifstream file(pdb_file);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open PDB file.");
    }

    std::vector<std::vector<Point3D>> models;
    std::vector<Point3D> current_model;

    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, 5) == "MODEL") {
            if (!current_model.empty()) {
                models.push_back(current_model);
                current_model.clear();
            }
        } else if (line.substr(0, 4) == "ATOM" && line.substr(12, 4) == " CA ") {
            double x = std::stod(line.substr(30, 8));
            double y = std::stod(line.substr(38, 8));
            double z = std::stod(line.substr(46, 8));
            current_model.push_back({x, y, z});
        }
    }

    if (!current_model.empty()) {
        models.push_back(current_model);
    }

    return models;
}

// Calculate the pseudo-torsion angle defined by four consecutive Cα atoms
double calculate_pseudo_torsion_angle(const Point3D& a, const Point3D& b, const Point3D& c, const Point3D& d) {
    Point3D ab = b - a;
    Point3D bc = c - b;
    Point3D cd = d - c;

    Point3D n1 = normalize(cross(ab, bc));
    Point3D n2 = normalize(cross(bc, cd));
    Point3D bc_normalized = normalize(bc);

    double cos_theta = dot(n1, n2);
    double sin_theta = dot(cross(n1, n2), bc_normalized);

    return std::atan2(sin_theta, cos_theta) * (180.0 / M_PI); // Convert radians to degrees
}

// Compute order parameters for pseudo-torsion angles
void compute_order_parameters(const std::vector<std::vector<Point3D>>& models) {
    size_t n_residues = models[0].size();
    size_t n_models = models.size();

    std::vector<std::vector<double>> pseudo_torsions_per_model;

    for (const auto& model : models) {
        std::vector<double> pseudo_torsions;
        for (size_t i = 0; i < n_residues - 3; ++i) {
            double angle = calculate_pseudo_torsion_angle(model[i], model[i + 1], model[i + 2], model[i + 3]);
            pseudo_torsions.push_back(angle);
        }
        pseudo_torsions_per_model.push_back(pseudo_torsions);
    }

    std::vector<double> mean_torsions(n_residues - 3, 0.0);
    std::vector<double> variances(n_residues - 3, 0.0);

    for (size_t i = 0; i < n_residues - 3; ++i) {
        for (const auto& pseudo_torsions : pseudo_torsions_per_model) {
            mean_torsions[i] += pseudo_torsions[i];
        }
        mean_torsions[i] /= n_models;

        for (const auto& pseudo_torsions : pseudo_torsions_per_model) {
            double diff = pseudo_torsions[i] - mean_torsions[i];
            variances[i] += diff * diff;
        }
        variances[i] /= n_models;
    }

    // Print results
    std::cout << "Pseudo-torsion Order Parameters:\n";
    std::cout << "Mean Torsions:\n";
    for (double mean : mean_torsions) {
        std::cout << std::fixed << std::setprecision(2) << mean << " ";
    }
    std::cout << "\nVariances:\n";
    for (double variance : variances) {
        std::cout << std::fixed << std::setprecision(2) << variance << " ";
    }
    std::cout << "\n";
}

// Main function
int main() {
    std::string pdb_file = "1d3z.pdb"; // Replace with your PDB file path

    try {
        auto models = parse_ca_atoms(pdb_file);

        if (models.size() < 2) {
            std::cerr << "Error: The PDB file must contain multiple models for CA_CORE.\n";
            return 1;
        }

        compute_order_parameters(models);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

