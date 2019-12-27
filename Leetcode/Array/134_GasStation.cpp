//#include <iostream>
//#include <vector>
//#include <cassert>
//
//int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) 
//{
//    assert(gas.size() == cost.size());
//
//    int pos = 0;
//    int len = gas.size();
//    int res = 0;
//    int count = 0;
//
//    for (pos = 0; pos < gas.size(); ++pos)
//    {
//        count = 0;
//        res = 0;
//        for (int i = 0; i < gas.size(); ++i)
//        {
//            res += gas[(pos + i) % len];
//            res -= cost[(pos + i) % len];
//
//            if (res < 0)
//                break;
//
//            ++count;
//        }
//
//        if (count == len)
//            return pos;
//    }
//
//    return -1;
//}
//
//int canCompleteCircuit2(std::vector<int> &gas, std::vector<int> &cost) {
//    int start(0), total(0), tank(0);
//    //if car fails at 'start', record the next station
//    for (int i = 0; i < gas.size(); i++)
//    {
//        if ((tank = tank + gas[i] - cost[i])<0)
//        {
//            start = i + 1;
//            total += tank;
//            tank = 0;
//        }
//    }
//
//    return (total + tank < 0) ? -1 : start;
//}
//
//int main()
//{
//    std::vector<int> gas = { 1, 2, 3, 4, 5 };
//    std::vector<int> cost = { 3, 4, 5, 1, 2 };
//    std::vector<int> gas2 = { 2, 3, 4 }, cost2 = {3, 4, 3};
//    std::cout << canCompleteCircuit2(gas, cost) << std::endl;
//
//    system("pause");
//    return 0;
//}