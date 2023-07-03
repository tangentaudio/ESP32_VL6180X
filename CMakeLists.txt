set(COMPONENT_SRCS
    src/VL6180X.c
    api/core/src/vl6180x_api.c
    api/platform/src/vl6180x_i2c.c
    api/platform/src/vl6180x_platform.c
)

set(COMPONENT_ADD_INCLUDEDIRS
    src
    api/config
    api/core/inc
    api/platform/inc
    
)
set(COMPONENT_REQUIRES driver) 
register_component()
