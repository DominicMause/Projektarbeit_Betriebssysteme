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

QList<Process> Helper::roundRobin(QList<Process>)
{

}


