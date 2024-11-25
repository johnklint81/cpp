.PHONY : all

# Targets
TARGETS : 111 112 113 122 123 131 132 133 141 142 143 151 152 153 161 162 163 \
	      211 212

# Default rule
all : $(TARGETS)

# Build pattern, $@ expands to the target name (e.g. 111)
# $< expands to the first prerequisite (e.g. 111.cpp)

%: %.cpp
	g++ -o $@ $<
