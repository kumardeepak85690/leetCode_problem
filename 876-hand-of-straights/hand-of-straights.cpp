class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> cardCount;
    for (int card : hand) {
        cardCount[card]++;
    }

    for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
        if (it->second > 0) {
            int count = it->second;
            for (int i = 0; i < groupSize; ++i) {
                if (cardCount[it->first + i] < count) {
                    return false;
                }
                cardCount[it->first + i] -= count;
            }
        }
    }

    return true;
    }
};