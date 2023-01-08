#ifndef CPU_USAGE_H
#define CPU_USAGE_H

struct cpuusage{
    unsigned long long idle;
    unsigned long long nonIdle;
    unsigned long long total;
};

struct cpustat{
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

double cpuusage_average();

#endif