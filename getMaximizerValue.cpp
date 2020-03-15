#include <bits\stdc++.h>
using namespace std;

int getLeftChild(int node) { return node * 2; }
int getRightChild(int node) { return node * 2 + 1; }

int minimax(int curDepth, int nodeIndex, bool isMaximizer, vector<int> scores, int h)
{
    if (curDepth == h)
    { // we finished the tree
        return scores[nodeIndex];
    }
    if (isMaximizer)
    { // I am a maximizer node
        int leftValue = minimax(curDepth + 1, getLeftChild(nodeIndex), false, scores, h);
        int rightValue = minimax(curDepth + 1, getRightChild(nodeIndex), false, scores, h);
        return max(leftValue, rightValue); // get max from my children
    }
    else
    {
        int leftValue = minimax(curDepth + 1, getLeftChild(nodeIndex), true, scores, h);
        int rightValue = minimax(curDepth + 1, getRightChild(nodeIndex), true, scores, h);
        return min(leftValue, rightValue);
    }
}

int main()
{
    vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = scores.size();
    int h = ceil(log2(n));
    int maximizerValue = minimax(0, 0, true, scores, h);
    cout << maximizerValue << endl; // 12
}