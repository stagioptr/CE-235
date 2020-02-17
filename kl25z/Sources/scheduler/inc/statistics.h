typedef struct
{
	uint32_t ticks;
	uint32_t count;
}statistiucs_t;

statistiucs_t scheduler_statistcs_getCount ( void );
void scheduler_statistcs_addTime ( statistiucs_t* totals, statistiucs_t* countBeforeOperation );
statistiucs_t scheduler_statistcs_differenceOfTime ( statistiucs_t* start, statistiucs_t* stop );
uint32_t scheduler_statistcs_convertToMicroseconds ( statistiucs_t* value );
void scheduler_statistcs_incrementCount ( void );
