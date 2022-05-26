#include <vector>
#include <cstdio>


class SqInRect
{
public:
    static std::vector<int> sqInRect(int lng, int wdth)
    {
        if (lng == wdth) return {};

        int max_side = lng;
        int min_side = wdth;
        if (lng < wdth) {
            max_side = wdth;
            min_side = lng;
        }
        std::vector<int> res;
        int diff;
        do {
            int countSqMinSide = max_side / min_side;
            if (countSqMinSide > 0) 
            {
                for (int i = 0; i < countSqMinSide; ++i) 
                {
                    res.push_back(min_side);
                }
                diff = max_side - countSqMinSide*min_side;
            }
            else
            {
                diff = max_side - min_side;
            }

            max_side = min_side;
            min_side = diff;

        } while (diff > 0);

        /// Solution on example sqInRect(20, 14):
        //
        // countSqMinSide = 20 / 14 = 0 
        // diff = 20 - 14 = 6
        // max_side = 14
        // min_side = 6
        //
        // countSqMinSide = 14 / 6 = 2
        // diff = 14 - 2 * 6 = 2
        // max_side = 6
        // min_side = 2
        //
        // countSqMinSide = 6 / 2 = 3
        // diff = 6 - 3 * 2 = 0
        //
        // [sqInRect(20, 14) -> 14, 6, 6, 2, 2, 2].
        
        return res;
    }
};


int main()
{
    SqInRect test;
    std::vector<int> ans = test.sqInRect(20, 14);
    
    for (int x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}

