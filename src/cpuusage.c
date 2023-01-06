#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../inc/cpuusage.h"

static struct cpustat cpustat_reader(){
    struct cpustat r;
    
    FILE *fp;
 
    if ((fp = fopen("/proc/stat", "r")) == NULL){
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%*s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &r.user, &r.nice,
        &r.system, &r.idle, &r.iowait, &r.irq, &r.softirq, &r.steal, &r.guest, &r.guest_nice);

    fclose(fp);

    return r;
}

static struct cpuusage cpuusage_from_cpustat(struct cpustat s){
    struct cpuusage cu;

    cu.idle = s.idle + s.iowait;
    cu.nonIdle = s.user + s.nice + s.system + s.irq + s.softirq + s.steal; 
    cu.total = cu.idle + cu.nonIdle;

    return cu;
}

static float cpuusage_analyzer(struct cpuusage _prevCu, struct cpuusage _currCU){
    struct cpuusage prevCU = _prevCu;
    struct cpuusage currCU = _currCU;
    
    unsigned long long total = currCU.total - prevCU.total;
    unsigned long long idle = currCU.idle - prevCU.idle;

    return (float)(total - idle)/total * 100;
} 

void cpuusage_printer(){
    struct cpuusage prev = {0};
    
    while (1){
        struct cpustat stats = cpustat_reader();
        struct cpuusage curr = cpuusage_from_cpustat(stats);

        float avg = cpuusage_analyzer(prev, curr);
        prev = curr;
        
        printf("%.1f%%\n", avg);
        sleep(1);
    }
}
