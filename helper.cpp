#include "helper.h"
#include "QtDebug"

QList<Process> Helper::firstComeFirstServed(QList<Process> list){
    QList<Process> result;
    result.reserve(list.size());
    std::reverse_copy(list.begin(),list.end(),std::back_inserter(result));
    return result;
}

QList<Process> Helper::shortestJobFirst(QList<Process> list){
    std::sort(list.begin(),list.end(),[](Process p1, Process p2) -> bool { return p1.getProcessSize() < p2.getProcessSize(); });
    return list;
}


