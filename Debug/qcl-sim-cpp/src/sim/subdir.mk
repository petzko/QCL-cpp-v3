################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../qcl-sim-cpp/src/sim/SimLoop.cpp \
../qcl-sim-cpp/src/sim/SimSettings.cpp 

OBJS += \
./qcl-sim-cpp/src/sim/SimLoop.o \
./qcl-sim-cpp/src/sim/SimSettings.o 

CPP_DEPS += \
./qcl-sim-cpp/src/sim/SimLoop.d \
./qcl-sim-cpp/src/sim/SimSettings.d 


# Each subdirectory must supply rules for building sources it contributes
qcl-sim-cpp/src/sim/%.o: ../qcl-sim-cpp/src/sim/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/SHARED/Matlab_Linux/extern/include -I/home/petzko/libraries/gsl-1.9/install/include -I"/home/petzko/workspace/qcl-sim-ptrArithmetic/qcl-sim-cpp/src" -O3 -g3 -Wall -fopenmp -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


