#include <stdio.h>
#include <stdlib.h>

struct cpuusage{
    unsigned long long idleTime;
    unsigned long long workingTime;
};

struct cpustat{
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

struct cpustat reader(){
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

int main(){
    struct cpustat stats = reader();

    printf("%llu\n", stats.nice);
}