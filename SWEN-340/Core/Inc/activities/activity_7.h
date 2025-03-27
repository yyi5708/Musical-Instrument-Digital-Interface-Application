#ifndef INC_ACTIVITIES_ACTIVITY_7_H_
#define INC_ACTIVITIES_ACTIVITY_7_H_

#include "stdint.h"

struct systick {
	uint32_t CSR ;
	uint32_t RVR ;
	uint32_t CVR ;
	uint32_t CALIB ;
};

void run_activity_7() ;

#endif
