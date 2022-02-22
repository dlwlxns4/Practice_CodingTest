#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Music
{
    string genre;
    int playCount;

    bool operator<(const Music& other)
    {
        return playCount > other.playCount;
    }
};

bool desc(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> hash;
    unordered_map<string, int> totalCount;
    vector<Music> music;



    for (int i = 0; i < plays.size(); ++i)
    {
        hash[genres[i]].push_back({ i, plays[i] });
        sort(hash[genres[i]].begin(), hash[genres[i]].end(), desc);
        totalCount[genres[i]] += plays[i];
    }

    for (auto it = totalCount.begin(); it != totalCount.end(); ++it)
    {
        music.push_back({ (*it).first, (*it).second });
    }
    sort(music.begin(), music.end());



    for (int i = 0; i < music.size(); ++i)
    {
        answer.push_back(hash[music[i].genre][0].first);
        if (hash[music[i].genre].size() != 1)
            answer.push_back(hash[music[i].genre][1].first);
    }


    return answer;
}