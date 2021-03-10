#include "BMS_BatteryCheck.h"


BatteryData_t Temparature_Specification = {
  0.0,            
  45.0,  
  2.25,
  42.75,
  "Temparature" 
  };
  
  
/**
***************************************************************************************************
* Function Name: IsTemperatureStable
* 
* Function Description: Checks the Temperature is within the range of permissible working limit.
*
* \param  float Temperature
*         
* \return  Integer
* \retval  BATTERY_HEALTH_OK or BATTERY_HEALTH_NOT_OK indicating temperature status.
***************************************************************************************************
*/
int IsTemperatureStable(float Temperature)
{
    int isTemparaturestable = BATTERY_HEALTH_OK;
    if (Temperature<=Temparature_Specification.BatteryDataLowerWarningLimit )
    {
         isTemparaturestable = BATTERY_HEALTH_NOT_OK;
        HandleBatteryDataOn_Lowerlimit(Temparature_Specification, Temperature);
      
    }
    else if (Temperature>Temparature_Specification.BatteryDataUpperWarningLimit)
    {
          isTemparaturestable = BATTERY_HEALTH_NOT_OK;
        HandleBatteryDataOn_Upperlimit(Temparature_Specification, Temperature);
    }
    else
    {
       PrintBatteryHealthStatus(Temparature_Specification,isTemparaturestable );
    }
    
    return isTemparaturestable;
}