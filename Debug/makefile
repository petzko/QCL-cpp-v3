################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include qcl-sim-cpp/src/solvers/subdir.mk
-include qcl-sim-cpp/src/sim/subdir.mk
-include qcl-sim-cpp/src/parsers/subdir.mk
-include qcl-sim-cpp/src/matrix/subdir.mk
-include qcl-sim-cpp/src/common/subdir.mk
-include qcl-sim-cpp/src/subdir.mk
-include qcl-sim-cpp/build/subdir.mk
-include qcl-sim-cpp/Debug/test/subdir.mk
-include qcl-sim-cpp/Debug/src/solvers/subdir.mk
-include qcl-sim-cpp/Debug/src/sim/subdir.mk
-include qcl-sim-cpp/Debug/src/parsers/subdir.mk
-include qcl-sim-cpp/Debug/src/matrix/subdir.mk
-include qcl-sim-cpp/Debug/src/common/subdir.mk
-include qcl-sim-cpp/Debug/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: qcl-sim-ptrArithmetic

# Tool invocations
qcl-sim-ptrArithmetic: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/mnt/SHARED/Matlab_Linux/bin/glnxa64 -L/home/petzko/libraries/gsl-1.9/install/lib -o "qcl-sim-ptrArithmetic" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) qcl-sim-ptrArithmetic
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
