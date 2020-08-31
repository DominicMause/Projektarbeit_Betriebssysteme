#include "helper.h"
#include "QtDebug"

QList<Process> Helper::firstComeFirstServed(QList<Process> list){
    for(Process p : list){
        p.execute();
    }
    return list;
}

QList<Process> Helper::lastComeFirstServed(QList<Process> list){
    QList<Process> result;
    result.reserve(list.size());
    std::reverse_copy(list.begin(),list.end(),std::back_inserter(result));
    for(Process p : list){
        p.execute();
    }
    return result;
}

QList<Process> Helper::shortestJobFirst(QList<Process> list){
    std::sort(list.begin(),list.end(),[](Process p1, Process p2) -> bool { return p1.getProcessSize() < p2.getProcessSize(); });
    for(Process p : list){
        p.execute();
    }
    return list;
}

QList<Process> Helper::roundRobin(QList<Process> inList)
{
    QList<Process> outList = QList<Process>();
    int finishedCount = 0;
    int rounds = 0;

    while(finishedCount < inList.length()&& rounds < 100000){

        for(Process p : inList){
             if(p.getProcessSize() > processingTime*rounds){
                p.setProcessSize(p.getProcessSize()-processingTime*rounds);
                outList.append(p);

            } else if(p.getProcessSize()<= processingTime *rounds){
                p.setProcessSize(0);
                outList.append(p);
                finishedCount++;
            }
        }
        rounds++;
    }

    return outList;
}

QList<Process> Helper::roundRobinWithPrio(QList<Process> inList)
{
    QList<Process> outList = QList<Process>();
    int finishedCount = 0;
    int rounds = 0;
    int highCount = 0;
    int midCount = 0;
    int lowCount = 0;

    for(Process p : inList){

        switch (p.getPriority()) {
        case 0:lowCount++;
            break;
        case 1: midCount++;
            break;
        case 2: highCount++;
            break;

        }
    }



    //High Prio
    while(finishedCount < highCount && rounds < 100000){

        for(Process p : inList){
            if(p.getPriority() == 2){
                 if(p.getProcessSize() > processingTime*rounds){
                    p.setProcessSize(p.getProcessSize()-processingTime*rounds);
                    outList.append(p);

                } else if(p.getProcessSize()<= processingTime *rounds){
                    p.setProcessSize(0);
                    outList.append(p);
                    finishedCount++;
                }
            }
        }
        rounds++;
    }

    //Mid Prio
    rounds = 0;
    while(finishedCount < midCount && rounds < 100000){

        for(Process p : inList){
            if(p.getPriority() == 1){
                 if(p.getProcessSize() > processingTime*rounds){
                    p.setProcessSize(p.getProcessSize()-processingTime*rounds);
                    outList.append(p);

                } else if(p.getProcessSize()<= processingTime *rounds){
                    p.setProcessSize(0);
                    outList.append(p);
                    finishedCount++;
                }
            }
        }
        rounds++;
    }

    //LowPrio

    rounds = 0;
    while(finishedCount < lowCount && rounds < 100000){

        for(Process p : inList){
            if(p.getPriority() == 0){
                 if(p.getProcessSize() > processingTime*rounds){
                    p.setProcessSize(p.getProcessSize()-processingTime*rounds);
                    outList.append(p);

                } else if(p.getProcessSize()<= processingTime *rounds){
                    p.setProcessSize(0);
                    outList.append(p);
                    finishedCount++;
                }
            }
        }
        rounds++;
    }

    return outList;
}

