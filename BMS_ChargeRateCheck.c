#include "BMS_BatteryCheck.h"

BatteryData_t ChargeRate_Specification = {
  0.0,            
  0.8, 
  0.04,
  0.76,
  "ChargeRate" 
  };
  
/**
 ***************************************************************************************************
 * Function Name: IschargeRateStable
 * 
 * Function Description: Checks the ChargeRate is within the range of permissible working limit.
 *
 * \param  float chargeRate
 *         
 * \return  Integer
 * \retval  BATTERY_HEALTH_OK or BATTERY_HEALTH_NOT_OK indicating Charge rate status.
 ***************************************************************************************************
 */
 
int IschargeRateStable(float chargeRate)
{
  int isChargeRatestable = BATTERY_HEALTH_OK;
    if (chargeRate<=ChargeRate_Specification.BatteryDataLowerWarningLimit )
    {
         isChargeRatestable = BATTERY_HEALTH_NOT_OK;
        HandleBatteryDataOn_Lowerlimit(ChargeRate_Specification, chargeRate);
      
    }
    else if (chargeRate>ChargeRate_Specification.BatteryDataUpperWarningLimit)
    {
        isChargeRatestable = BATTERY_HEALTH_NOT_OK;
        HandleBatteryDataOn_Upperlimit(ChargeRate_Specification, chargeRate);
    }
    else
    {
       PrintBatteryHealthStatus(ChargeRate_Specification,isChargeRatestable );
    }
  return isChargeRatestable;
}
