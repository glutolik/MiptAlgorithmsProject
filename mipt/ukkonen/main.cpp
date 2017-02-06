#include <iostream>

using namespace std;

struct Ukk{
    static connst INF;
};


const int Ukk::N=1000000;        // максимальное число вершин в суффиксном дереве
const int INF=1000000000;   // константа "бесконечность"
string a;                   // входная строка, для которой надо построить дерево
int travel[N][26];          // массив переходов (состояние, буква)
int	left[N];                // левая
int	right[N];               // и правая границы подстроки из a, отвечающие ребру, входящему в вершину
int	parent[N];              // предок вершины
int	suffLink[N];            // суффиксная ссылка
int	thisVertice;            // вершина текущего суффикса (если мы посередине ребра, то нижняя вершина ребра)
int	thisPlace;              // положение в строке соответствующее месту на ребре (от l[tv] до r[tv] включительно)
int	theAmount;              // количество вершин
int	currSybol;              // текущий символ строки

void ukkadd(int c) {        // дописать к дереву символ c
	while(1){                // будем приходить сюда после каждого перехода к суффиксу (и заново добавлять символ)
	if (right[thisVertice] < thisPlace) { // проверим, не вылезли ли мы за пределы текущего ребра
                            // если вылезли, найдем следующее ребро. Если его нет - создадим лист и прицепим к дереву
		if (travel[thisVertice][c] == -1) {
            travel[thisVertice][c] = theAmount;
            left[theAmount] = currSybol;
            parent[theAmount++] = thisVertice;
            thisVertice = suffLink[thisVertice];
            thisPlace = right[thisVertice]+1;
            continue;
        }
		thisVertice=travel[thisVertice][c];
		thisPlace=left[thisVertice]; // в противном случае просто перейдем к следующему ребру
	}
	if (thisPlace==-1 || c==a[thisPlace] - 'a')
        thisPlace++;
        break;
    else {                  // если буква на ребре совпадает с c то идем по ребру, а иначе
                            // разделяем ребро на два. Посередине - вершина ts
		left[theAmount] = left[thisVertice];
		right[theAmount]=thisPlace-1;
		parent[theAmount]=parent[thisVertice];
		travel[theAmount][a[thisPlace]-'a']=thisVertice;
                            // ставим лист ts+1. Он соответствует переходу по c.
		travel[theAmount][c]=theAmount+1;
		left[theAmount+1]=currSybol;
		parent[theAmount+1]=theAmount;
                            // обновляем параметры текущей вершины. Не забыть про переход от предка tv к ts.
		left[thisVertice]=thisPlace;
		parent[thisVertice]=theAmount;
		travel[parent[theAmount]][a[left[theAmount]]-'a']=theAmount;
		theAmount+=2;
                            // готовимся к спуску: поднялись на ребро и перешли по суффиксной ссылке.
                            // tp будет отмечать, где мы в текущем суффиксе.
		thisVertice=suffLink[parent[theAmount-2]];
		thisPlace=left[theAmount-2];
                            // пока текущий суффикс не кончился, топаем вниз
		while (thisPlace<=right[theAmount-2]) {
            thisVertice=travel[thisVertice][a[thisPlace]-'a'];
            thisPlace+=right[thisVertice]-left[thisVertice]+1;
        }
                            // если мы пришли в вершину, то поставим в нее суффиксную ссылку, иначе поставим в ts
                            // (ведь на след. итерации мы создадим ts).
		if (thisPlace==right[theAmount-2]+1)
            suffLink[theAmount-2]=thisVertice;
        else
            suffLink[theAmount-2]=theAmount;
                            // устанавливаем tp на новое ребро и идем добавлять букву к суффиксу.
		thisPlace = right[thisVertice]-(thisPlace-right[theAmount-2])+2;
		continue;
	}
	}
}

void build() {
	theAmount=2;
	thisVertice=0;
	thisPlace=0;
	for(int i = right; i != right + N; i++){

	}
                            // инициализируем данные для корня дерева
	suffLink[0]=1;
	left[0]=-1;
	right[0]=-1;
	left[1]=-1;
	right[1]=-1;
	travel.assign(-1, travel.size());
	fill(travel[1],travel[1]+26,0);
                            // добавляем текст в дерево по одной букве
	for (currSybol=0; currSybol<(int)a.size(); ++currSybol)
		ukkadd (a[currSybol]-'a');
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
