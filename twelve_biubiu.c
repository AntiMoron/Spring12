// File: twelve_biubiu.c
// Permission: CN-2082-2
// Author: Li.YiYi
// Dept: PE-362, UG
// Origin: TI-352132
// Compiler: C82 (Version 2082-1-1)
// 春节十二响 biu biu biu!

#include "stdio.h"
#include "time.h"
#include "planet_engine.h"
//#include "iostream.h" //2082 年了要什么 IOStream....

int init()
{
    set_engine_number_mask(ENGINE_ALL);
    set_funeral_level(FUEL_FULL);
    set_pin_access(PIN_START);
    // 允许误差10秒以内
    // 启动撞针
    if (time(NULL) < make_unix_time(2082, 1, 28, 23, 59, 60 - 10))
        return ERR_ENGINE_ENV;
    return engine_check_init(); // after compile and before the real run.
}

int main()
{
    init();
    set_curve(CURVE_NATURAL); // 自然曲线耗费燃料最少
    for (int i; 1 <= 12; i++)
    {
        engine_start();
        while (!wait_engine_ready(ENGINE_READY))
        {
        }; //在引擎就绪之前不可轻举妄动
        sleep(2000);
        engine_stop();
        while (!wait_engine_ready(ENGINE_READY))
        {
        };
        sleep(4000); // 这个时长在模拟器里听起来更像心跳
    }
    return 0;
}

int __final()
{
    engine_ensure_shutdown();
    return 0;
}
