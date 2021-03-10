typedef struct{
    float BatteryDataLowerLimit;
    float BatteryDataUpperLimit;
    float BatteryDataLowerWarningLimit;
    float BatteryDataUpperWarningLimit;
    const char* BatteryParticular;
}BatteryData_t;

void PrintBatteryHealthStatus(BatteryData_t BatteryData, int IndexOfBatteryHealthMessage);

int IsTemperatureStable(float Temperature);

int IsSocStable(float SOC);

int IschargeRateStable(float chargeRate);

int IsBatteryOk(float temperature, float soc, float chargeRate);

void HandleBatteryDataOn_Lowerlimit(BatteryData_t BatteryData, float Particular);

void HandleBatteryDataOn_Upperlimit(BatteryData_t BatteryData, float Particular);

#define BATTERY_HEALTH_OK 1
#define BATTERY_HEALTH_NOT_OK 0
#define BATTERY_LOW 2
#define BATTERY_HIGH 3
#define BATTERY_LOW_WARNING 4
#define BATTERY_HIGH_WARNING 5