#include "helper.h"
#include "QtDebug"

QList<Process> Helper::firstComeFirstServed(QList<Process> list){
    QList<Process> result;
    result.reserve(list.size());
    std::reverse_copy(list.begin(),list.end(),std::back_inserter(result));

    return result;
}
