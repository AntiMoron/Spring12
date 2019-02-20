const int ENGINE_ALL = -1;
const int ERR_ENGINE_ENV = -1;
typedef int BOOL;
typedef enum PINSTATE
{
    PIN_START = 1
} pinstate;

typedef enum FUELSTATE
{
    FUEL_FULL = 100,
    FUEL_HIGH = 70,
    FUEL_LOW = 20,
    FUEL_EMPTY = 0
} fuelstate;

typedef enum ENGINESTATE
{
    ENGINE_FAIL = -1,
    ENGINE_READY = 0,
    ENGINE_STARTED = 1
} enginestate;

typedef enum CURVETYPE
{
    CURVE_NONE = 0,
    CURVE_NATURAL = 1
} curvetype;

void set_engine_number_mask(int mask);
void set_funeral_level(int state);
void set_pin_access(int state);
void set_curve(int wantReadyState);
int wait_engine_ready(int state);
int engine_check_init();
BOOL engine_start();
BOOL engine_stop();
int engine_ensure_shutdown();

void sleep(long time);
time_t make_unix_time(int year, int mon, int day, int hour, int min, int sec);