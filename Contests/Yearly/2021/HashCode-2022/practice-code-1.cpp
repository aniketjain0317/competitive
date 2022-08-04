// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define fs first
#define sn second
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define cp2(x) (__builtin_popcountll(x)==1)
#define lp2(x) (__builtin_ctzll(x))
#define tc(tno) cout << "Case #" << tno << ": "
#define dsp(x) cout << #x << ": " << x << ", "
#define dnl(x) cout << #x << ": " << x << endl
#define cnlret(x) {cnl(x); return;}


template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T>             ostream& operator<<(ostream& os,  set<T>  v)   {os<<"{"; for (auto& i : v) os << i << ','; os<<"}"; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> bool chmin(T& a, U b){if (a > b) {a = b; return true;} return false;}
template<typename T, typename U> bool chmax(T& a, U b){if (a < b) {a = b; return true;} return false;}


#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const ll MOD = 1000000007;
const ll INF = 1LL<<62;
const int N = 100005;

class Person
{
public:
  int id;
  string name;
  int skill_count;
  map<int,int> skills;
  int available;
};

class Project
{
public:
  int id;
  string name;
  int score;
  int days;
  int best_before;
  int max_time;
  int skill_count;
  double avg_skill;
  vector<pair<int,int>> skills;

  Project(int i, string nm, int d, int s, int b, int r)
  {
    name = nm;
    id = i;
    days = d;
    score = s;
    best_before = b;
    skill_count = r;
    max_time = best_before + skill_count;
    avg_skill = 0;
  }

  Project()
  {
    id = -1;
  }
};

class Skill
{
public:
  int id;
  int importance;
  string name;
  vector<int> people;
};

vector<Person> people;
vector<Project> projects;
vector<Skill> skills;
map<string, int> skillID;
int lsID = 0;
int C, P;

int show = 0;

class Answer
{
public:
  int count;
  int score;
  vector<pair<int, vi>> solutions;

  Answer()
  {
    count = 0;
    score = 0;
  }

  void addSoln(int projectID, vi &ids)
  {
    solutions.pb({projectID, ids});
    count++;
  }

  void printAnswer()
  {
    cnl(count);
    for(auto &[projectID, ids]: solutions)
    {
      cnl(projects[projectID].name);
      for(auto &id: ids) csp(people[id].name); cout << endl;
    }
  }
};

class SolnProj
{
public:
  int projectID;
  vector<int> peopleID;
  set<int> setID;
  int endTime;
  map<int,int> maxLevel;
  int incSkill;
  int newSkill;
  int possible;
  Project &project;

  SolnProj(int id) : project(projects[id])
  {
    projectID = id;
    peopleID.resize(projects[projectID].skill_count, -1);
    endTime = 0;
    incSkill = -1;
    newSkill = 0;
    possible = -1;
  }

  int addPerson(int i, int id)
  {
    // assume checkPerson is already called
    auto &person = people[id];
    auto &[req, skill] = project.skills[i];
    peopleID[i] = id;
    setID.insert(id);

    int t = person.available + project.days;
    chmax(endTime, t);
    chmax(maxLevel[skill], person.skills[skill]);
    return 1;
  }

  int findPerson(int i)
  {
    vvi infoList;
    auto &[req, skill] = project.skills[i];

    if(req==1 && maxLevel[skill]>=1) fr(id,0,C)
    {
      vi info = checkPerson(i, id);
      if(!info[0] || !info[1] || !info[2]) continue;
      infoList.pb(checkPerson(i, id));
    }
    else for(auto id: skills[skill].people)
    {
      vi info = checkPerson(i, id);
      if(!info[0] || !info[1] || !info[2]) continue;
      infoList.pb(checkPerson(i, id));
    }

    if(infoList.empty()) return -1;
    sort(all(infoList), [&](auto &a, auto &b) {return a[1]>b[1];});
    return infoList[0][3];
  }

  vector<int> checkPerson(int i, int id)
  {
    int cs = !setID.count(id);
    int cl = checkLevel(i, id);
    int ct = checkTime(i, id);
    return {cs, cl, ct, id};
  }

  int checkPossible()
  {
    if(possible!=-1) return possible;
    for(auto &id: peopleID) if(id==-1) return possible = 0;
    return possible = 1;
  }

  int checkLevel(int i, int id)
  {
    // check for mentoring and level
    auto &person = people[id];
    auto &[req, skill] = project.skills[i];
    if(person.skills[skill] > req) return 1;
    if(person.skills[skill] == req) return 2;
    if(person.skills[skill] == (req-1) && maxLevel[skill]>=req) return 3;
    return 0;
  }

  int checkTime(int i, int id)
  {
    auto &person = people[id];
    int t = person.available + project.days;
    if(t<=endTime) return 3;
    if(t<=project.best_before) return 2;
    if(t<=project.max_time) return 1;
    return 0;
  }

  pi checkMentor()
  {
    if(!checkPossible()) return {-2,-2};
    if(incSkill!=-1) return {newSkill, incSkill};
    incSkill = 0;
    fr(i,0,project.skill_count)
    {
      auto &[req, skill] = project.skills[i];
      if(people[peopleID[i]].skills[skill]<=req) incSkill+=1;
      if(people[peopleID[i]].skills[skill]==0) newSkill+=1;
    }
    return {newSkill, incSkill};
  }

  int finalize(Answer &ans)
  {
    if(!checkPossible()) return 0;
    for(auto id: peopleID) people[id].available=endTime;

    int score = project.score;
    if(endTime > project.best_before) score -= endTime - project.best_before;
    chmax(score, 0LL);

    fr(i,0,project.skill_count)
    {
      auto &[req, skill] = project.skills[i];
      if(people[peopleID[i]].skills[skill]<=req) people[peopleID[i]].skills[skill]+=1;
    }
    ans.score += score;
    ans.addSoln(projectID, peopleID);
    return 1;
  }
};


//
int getSkill(string sk)
{
  int skill;
  if(skillID.count(sk)) skill = skillID[sk];
  else
  {
    skill = lsID++;
    skillID[sk] = skill;
    skills.pb({});
    skills[skill].id = skill;
    skills[skill].name = sk;
  }
  return skill;
}

void getPeopleInput(int C)
{
  people.clear();
  people.resize(C);
  for(int i = 0; i<C; i++)
  {
    Person &person = people[i];
    string name; cin >> name;
    int n; cin >> n;
    person.id = i;
    person.name = name;
    person.skill_count = n;
    person.available = 0;
    for(int j = 0; j<n; j++)
    {
      string sk; cin >> sk;
      int skill = getSkill(sk);
      int level; cin >> level;
      people[i].skills[skill] = level;
      skills[skill].people.pb(i);
    }
  }
  for(auto &skill: skills)
  {
    int sk = skill.id;
    sort(all(skill.people), [&](int a, int b){
      return people[a].skills[sk]<people[b].skills[sk];
    });
  }
}

void getProjectsInput(int P)
{
  projects.clear();
  for(int i = 0; i<P; i++)
  {
    string name; cin >> name;
    int d,s,b,r; cin >> d >> s >> b >> r;
    Project project(i, name, d, s, b, r);
    for(int j = 0; j<r; j++)
    {
      string sk; cin >> sk;
      int skill = getSkill(sk);
      int level; cin >> level;
      project.skills.pb({level, skill});
      project.avg_skill += level;
    }
    project.avg_skill /= project.skill_count;
    projects.pb(project);
  }
}

SolnProj getSoln(int i)
{
  // make sure to finalize after.
  auto &project = projects[i];
  SolnProj soln(i);
  vi ordSkill(project.skill_count);
  fr(i,0,project.skill_count) ordSkill[i] = i;
  sort(all(ordSkill), [&](int a, int b){return project.skills[a] > project.skills[b];});
  for(auto j: ordSkill)
  {
    int id = soln.findPerson(j);
    if(id==-1) return soln;
    soln.addPerson(j, id);
  }
  return soln;
}

Answer getAnswer(vi &ordProj)
{
  Answer ans; ans.count = ans.score = 0;
  queue<int> q;
  for(auto &i: ordProj) q.push(i);
  fr(c,0,q.size())
  {
    int i = q.front(); q.pop();
    auto soln = getSoln(i);
    if(soln.finalize(ans)) c = 0;
    else q.push(i);
  }
  return ans;
}

vi bestFirstOrd;
Answer bestFirst()
{
  set<int> pids;
  fr(i,0,P) pids.insert(i);
  Answer ans;
  while(true)
  {
    int nxid = -1;
    pi mx = {-1, -1};
    for(auto &pid: pids)
    {
      auto soln = getSoln(pid);
      if(!soln.checkPossible()) continue;
      auto criteria = soln.checkMentor();
      if(chmax(mx, criteria)) nxid = pid;
    }
    if(nxid==-1) break;
    auto soln = getSoln(nxid);
    pids.erase(nxid);
    bestFirstOrd.pb(nxid);
    soln.finalize(ans);
  }
  for(auto &pid: pids) bestFirstOrd.pb(pid);
  return ans;
}

intt main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  freopen("myansB.txt","w",stdout);
  freopen("inputB.txt","r",stdin);
  srand(time(0));
  cin >> C >> P;
  getPeopleInput(C);
  getProjectsInput(P);
  vector<Person> reset_people(people);

  // MODIFICATION ALLOWED AT:
  // 1. Project Order.
  // 2. Skill Order.0000
  // 3. Choosing the person for the role.
  Answer finalAns = bestFirst();
  int finalScore = finalAns.score;
  vi finalOrd(bestFirstOrd);
  // auto getCriteria = [&](auto &pa)
  // {
  //   return -(pa.score/(double)pa.days)*pa.skill_count;
  // };



  // sort(all(finalOrd), [&](int a, int b) {
  //   auto &pa = projects[a], &pb = projects[b];
  //   if(pa.avg_skill!=pb.avg_skill) return pa.avg_skill < pb.avg_skill;
  //   if(pa.skill_count!=pb.skill_count) return pa.skill_count > pb.skill_count;
  //   if(pa.score!=pb.score) return pa.score>pb.score;
  //   if(pa.days!=pb.days) return pa.days<pb.days;
  //   if(pa.best_before!=pb.best_before) return pa.best_before<pb.best_before;
  //   return getCriteria(pa)<getCriteria(pb);
  // });
  fr(run_no,0,10000)
  {
    if(run_no % 500 == 0) dnl(run_no);
    people = reset_people;
    vi ordProj(finalOrd);
    // cin >> ordProj;
    if(run_no==5000) cin >> ordProj;
    else if(run_no)
    {
      vi lim({rand()%(P+1), rand()%(P+1)});
      sort(all(lim)); if(lim[0]==lim[1]) {lim = {0,P};};
      random_shuffle(ordProj.begin()+lim[0], ordProj.begin()+ lim[1]);
    }

    Answer ans = getAnswer(ordProj);
    if(chmax(finalScore, ans.score))
    {
      dsp(run_no);
      dnl(ans.score);
      dnl(ordProj);
      finalAns = ans;
      finalOrd = ordProj;
    }
  }
  cnl(finalOrd);
  cnl(finalAns.score);
  finalAns.printAnswer();
}


// Notes for problem B.
// TIME DOESNT MATTER AT ALL
// So, only things that matter:
//   a. whether there are enough experts.
//   b. whether they have enough skill.
