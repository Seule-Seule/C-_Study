/*==========================================================================================================
1）某市举行一场演讲比赛（ speech_contest ），共有24个人参加。比赛共三轮，前两轮为淘汰赛，第三轮为决赛。
2）比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛；
第一轮分为4个小组，每组6个人。比如100-105为一组，106-111为第二组，依次类推，
每人分别按照抽签（draw）顺序演讲。当小组演讲完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
第二轮分为2个小组，每组6人。比赛完毕，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
第三轮只剩下6个人，本轮为决赛，选出前三名。
4）比赛评分：10个评委打分，去除最低、最高分，求平均分
每个选手演讲完由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，求得剩下的8个成绩的平均分。
选手的名次按得分降序排列，若得分一样，按参赛号升序排名。
用STL编程，求解这个问题
1）	请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
2）	打印每一轮比赛后，小组比赛成绩和小组晋级名单
3）	打印决赛前三名，选手名称、成绩。
==========================================================================================================*/

#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"
#include "numeric"
#include "map"
#include "deque"
using namespace std;

class Speaker
{
public:
	string	speaker_name;
	int		speaker_results[3] = { 0 };
};

int create_speaker(vector<int>	&v, map<int, Speaker> &speechContestants)
{
	string str = "QWERTYUIOPASDFGHJKLZXCVBNM";
	random_shuffle(str.begin(), str.end());

	for (int i = 0; i < 24; i++)  // 产生选手信息
	{
		Speaker tmp;
		tmp.speaker_name = "选手";
		tmp.speaker_name = tmp.speaker_name + str[i];
		speechContestants.insert(pair<int, Speaker>(100+i, tmp));
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);
	}
	return 0;
}

int speech_contest_lottery(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}

int speech_contest(int index, vector<int> &v1, map<int, Speaker> &speechContestants, vector<int> &v2)
{
	multimap<int, int, greater<int> > mulitGroup;  // 成绩, 编号
	int tmpCount = 0;

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		tmpCount++;
		// 评委打分
		{
			deque<int> dequeScore;
			for (int j = 0; j < 10; j++)
			{
				int score = 50 + rand() % 50;
				dequeScore.push_back(score);
			}
			sort(dequeScore.begin(), dequeScore.end());
			dequeScore.pop_back(); // 去除最高分和最低分
			dequeScore.pop_front();
			int scoreSum = accumulate(dequeScore.begin(), dequeScore.end(), 0); // 求平均成绩
			int scoreAve = scoreSum / dequeScore.size();
			// 记录成绩 
			speechContestants[*it].speaker_results[index] = scoreAve;
			mulitGroup.insert(pair<int, int>(scoreAve, *it));
		}
		// 打印小组成绩
		if ((tmpCount % 6) == 0) 
		{
			cout << "\t小组赛成绩：" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = mulitGroup.begin(); mit != mulitGroup.end(); mit++)
			{
				// 编号 姓名 成绩 
				cout << mit->second << "\t" << speechContestants[mit->second].speaker_name << "\t" << mit->first << endl;
			}
			// 记录晋级人员
			while (mulitGroup.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator mit2 = mulitGroup.begin();
				v2.push_back(mit2->second);
				mulitGroup.erase(mit2);
			}
			mulitGroup.clear();
		}
	}
	return 0;
}

int speech_contest_results(int index, vector<int> &v, map<int, Speaker> &speechContestants)
{
	printf("\t第%d轮晋级名单：\n\n", index + 1);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "参赛编号：" << *it << "  选手姓名:" << speechContestants[*it].speaker_name 
			 << "  选手成绩：" << speechContestants[*it].speaker_results[index] << endl;
	}
	return 0;
}

int main() 
{
	int ret = 0;

	map<int, Speaker>	speechContestants;  // 参赛选手
	vector<int>			v1;   // 第一轮比赛名单
	vector<int>			v2;
	vector<int>			v3;
	vector<int>			v4;

	// 产生选手
	create_speaker(v1, speechContestants);

	// 第一轮 抽签 比赛 结果
	cout << "按下任意将开始第一轮比赛：" << endl;
	cin.get();
	speech_contest_lottery(v1);
	speech_contest(0, v1, speechContestants, v2);
	speech_contest_results(0, v2, speechContestants);

	// 第二轮
	cout << "按下任意将开始第二轮比赛：" << endl;
	cin.get();
	speech_contest_lottery(v2);
	speech_contest(1, v2, speechContestants, v3);
	speech_contest_results(1, v3, speechContestants);

	// 第三轮
	cout << "按下任意将开始第三轮比赛：" << endl;
	cin.get();
	speech_contest_lottery(v3);
	speech_contest(2, v3, speechContestants, v4);
	speech_contest_results(2, v4, speechContestants);

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}