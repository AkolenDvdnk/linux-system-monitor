#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct cpuusage{
    unsigned long long idle;
    unsigned long long nonIdle;
    unsigned long long total;
};

struct cpustat{
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

struct cpustat cpustat_reader(){
    struct cpustat r;
    
    FILE *fp;

    if ((fp = fopen("/proc/stat", "r")) == NULL){
        printf("File cannot be opened!\n");
        exit(1);
    }

    fscanf(fp, "%*s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &r.user, &r.nice,
        &r.system, &r.idle, &r.iowait, &r.irq, &r.softirq, &r.steal, &r.guest, &r.guest_nice);

    fclose(fp);

    return r;
}

struct cpuusage cpuusage_from_cpustat(struct cpustat s){
    struct cpuusage cu;

    cu.idle = s.idle + s.iowait;
    cu.nonIdle = s.user + s.nice + s.system + s.irq + s.softirq + s.steal; 
    cu.total = cu.idle + cu.nonIdle;

    return cu;
}

long double cpuusage_analyzer(struct cpuusage cu){
    struct cpuusage prevCU = cu;
    sleep(1);
    struct cpuusage currCU = cu;
    
    unsigned long long total = currCU.total - prevCU.total;
    unsigned long long idle = currCU.idle - prevCU.idle;

    return (long double)(total - idle)/total;
} 

int main(){
    struct cpustat stats = cpustat_reader();
    struct cpuusage cufcs = cpuusage_from_cpustat(stats);

    long double avg = cpuusage_analyzer(cufcs);

    printf("%Lf\n", avg);
}