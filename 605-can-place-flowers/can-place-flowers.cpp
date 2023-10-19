class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int cont = 0;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) {
                if (i == 0 || flowerbed[i - 1] == 0) {
                    if (i == m - 1 || flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1; // Plant a flower.
                        cont++;
                    }
                }
            }
        }
        return cont >= n;
    }
};
