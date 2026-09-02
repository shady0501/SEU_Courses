#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

struct Plane
{
	int id;
	int t;
	int pushQueueTime;
};

void printQueue(queue<Plane> a)
{
	if (a.empty())
	{
		cout << "空" << endl;
		return;
	}

	Plane b = a.front();
	queue<Plane> m;

	while (!a.empty())
	{
		cout << "(" << a.front().id << ", " << a.front().t << ")";
		m.push(a.front());
		a.pop();
	}
	cout << endl;
	a = m;
}

void  airportManagement(int lastTime)
{
	queue<Plane> landing1;
	queue<Plane> takeoff1;
	queue<Plane> landing2;
	queue<Plane> landingEmergency;
	queue<Plane> takeoff2;
	queue<Plane> takeoff3;

	double totalLandingWaitTime = 0.0;
	double totalTakeoffWaitTime = 0.0;
	double totalLandingRemainingTime = 0.0;
	int totalEmergencyLandings = 0;
	int lastLandingIdNumber = -2; // 从偶数ID开始
    int lastTakeoffIdNumber = -1; // 从奇数ID开始

	for (int i = 0; i < lastTime; ++i)
	{
		cout << "时间单位" << i + 1 << "：" << endl;

		// 生成随机数量的飞机进入着陆和起飞队列
        int landingNumber = rand() % 4;
        int takeoffNumber = rand() % 4;
		cout << "landingNumber = " << landingNumber << ", takeoffNumber = " << takeoffNumber << endl;

		// 处理进入着陆队列的飞机
        for (int i = 0; i < landingNumber; ++i)
		{
			lastLandingIdNumber += 2;
	        int landingTime = rand() % 6;
	        Plane plane;
	        plane.id = lastLandingIdNumber;
	        plane.t = landingTime;
			plane.pushQueueTime = i;

			if (landing1.empty())
				landing1.push(plane);
			else if (landing2.empty())
				landing2.push(plane);
			else if (plane.t > landing1.back().t || plane.t > landing2.back().t)
			{
				if (landing1.back().t > landing2.back().t)
					landing1.push(plane);
				else if (landing1.back().t < landing2.back().t)
					landing2.push(plane);
				else
					landing1.push(plane);
			}
			else
				landingEmergency.push(plane);
		}

		// 处理进入起飞队列的飞机
		for (int i = 0; i < takeoffNumber; ++i)
		{
			lastTakeoffIdNumber += 2;
			Plane plane;
			plane.id = lastTakeoffIdNumber;
			plane.t = 0;
			plane.pushQueueTime = i;
			
			if (takeoff1.size() < takeoff2.size() && takeoff1.size() < takeoff3.size())
				takeoff1.push(plane);
			else if (takeoff2.size() < takeoff1.size() && takeoff2.size() < takeoff3.size())
				takeoff2.push(plane);
			else if (takeoff3.size() < takeoff1.size() && takeoff3.size() < takeoff2.size())
				takeoff3.push(plane);
			else if (takeoff1.size() == takeoff2.size() && takeoff2.size() == takeoff3.size())
				takeoff3.push(plane);
			else if (takeoff1.size() == takeoff2.size() && takeoff2.size() < takeoff3.size())
				takeoff1.push(plane);
			else if (takeoff1.size() == takeoff3.size() && takeoff1.size() < takeoff2.size())
				takeoff1.push(plane);
			else if (takeoff2.size() == takeoff3.size() && takeoff2.size() < takeoff1.size())
				takeoff3.push(plane);
			else
				cout << "error";
		}

		// 模拟每个跑道的着陆和起飞
		if (!landingEmergency.empty())
		{
			int emergencyLandings = 0;

			while (landingEmergency.front().t == i && emergencyLandings <= 3)
			{
				totalLandingRemainingTime += landingEmergency.front().t - landingEmergency.front().pushQueueTime;
				landingEmergency.pop();
				emergencyLandings++;
				totalEmergencyLandings++;
			}

			if (3 - emergencyLandings == 1)
			{
				if (!landing1.empty() && !landing1.empty())
				{
					totalLandingRemainingTime += landing1.front().t - landing1.front().pushQueueTime;
					landing1.pop();
				}
				else if(!takeoff1.empty())
					takeoff1.pop();
			}
			else if (3 - emergencyLandings == 2)
			{
				if (!landing1.empty() && !landing1.empty())
				{
					totalLandingRemainingTime += landing1.front().t - landing1.front().pushQueueTime;
					landing1.pop();
				}
				else if (!takeoff1.empty())
					takeoff1.pop();

				if (!landing2.empty() && !landing2.empty())
				{
					totalLandingRemainingTime += landing2.front().t - landing2.front().pushQueueTime;
					landing2.pop();
				}
				else if (!takeoff2.empty())
					takeoff2.pop();
			}
			else if (3 - emergencyLandings == 3)
			{
				if (!landing1.empty() && !landing1.empty())
				{
					totalLandingRemainingTime += landing1.front().t - landing1.front().pushQueueTime;
					landing1.pop();
				}
				else if (!takeoff1.empty())
					takeoff1.pop();

				if (!landing2.empty() && !landing2.empty())
				{
					totalLandingRemainingTime += landing2.front().t - landing2.front().pushQueueTime;
					landing2.pop();
				}
				else if (!takeoff2.empty())
					takeoff2.pop();

				if(!takeoff3.empty())
					takeoff3.pop();
			}
		}
		else
		{
			if (!landing1.empty() && !landing1.empty())
			{
				totalLandingRemainingTime += landing1.front().t - landing1.front().pushQueueTime;
				landing1.pop();
			}
			else if (!takeoff1.empty())
				takeoff1.pop();

			if (!landing2.empty() && !landing2.empty())
			{
				totalLandingRemainingTime += landing2.front().t - landing2.front().pushQueueTime;
				landing2.pop();
			}
			else if (!takeoff2.empty())
				takeoff2.pop();

			if (!takeoff3.empty())
				takeoff3.pop();
		}

		totalTakeoffWaitTime = takeoff1.size() + takeoff2.size() + takeoff3.size();
		totalLandingWaitTime = landing1.size() + landing2.size() + landingEmergency.size();

		cout << "    队列：" << endl;
		cout << "      跑道一着陆队列：";  printQueue(landing1);
		cout << "      跑道二着陆队列：";  printQueue(landing2);
		cout << "      紧急着陆队列：";  printQueue(landingEmergency);
		cout << "      跑道一起飞队列：";  printQueue(takeoff1);
		cout << "      跑道二起飞队列：";  printQueue(takeoff2);
		cout << "      跑道三起飞队列：";  printQueue(takeoff3);
		cout << "    起飞平均等待时间： " << fixed << setprecision(2) << totalTakeoffWaitTime / lastTime << " 单位时间" << endl;
		cout << "    着陆平均等待时间： " << fixed << setprecision(2) << totalLandingWaitTime / lastTime << " 单位时间" << endl;
		cout << "    着陆平均剩余时间： " << fixed << setprecision(2) << totalLandingRemainingTime / lastTime << " 单位时间" << endl;
		cout << "    紧急降落飞机数： " << totalEmergencyLandings << endl;
	}
}

int main()
{
	int lastTime;
	cout << "输入最后的时间单位：";
	cin >> lastTime;

	airportManagement(lastTime);

	return 0;
}