set(CPU_FLAGS -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse)
set(DEVICE_DEFINES
    -DEFR32MG24B210F1536IM48=1 -DEFR32MG24=1 -DEFR32MG24B=1 -DBRD2703A=1
    -DSL_BOARD_NAME="BRD2703A" -DSL_CATALOG_PRESENT=1)
set(COMMON_FLAGS ${CPU_FLAGS} ${DEVICE_DEFINES}
    -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti
    -Wall -Wextra -Os -g3)