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

static struct cpustat cpustat_reader();
static struct cpuusage cpuusage_from_cpustat(struct cpustat s);
static float cpuusage_analyzer(struct cpuusage _prevCu, struct cpuusage _currCU);
void cpuusage_printer();

#endif