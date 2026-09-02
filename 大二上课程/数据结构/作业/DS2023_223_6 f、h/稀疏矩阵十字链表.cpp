#ifndef _ORTHOGONALLIST_HPP_
#define _ORTHOGONALLIST_HPP_
#include <cstring> 
#include <iostream> 

template <class T>
// 定义稀疏矩阵节点结构体
struct OrthogonalNode
{
	int row; int col; T element;
	// 非0元素所在行标、列表的后继链域 
	OrthogonalNode* down;
	OrthogonalNode* right;
};
template <class T> class OrthogonalList
{
private:
	// 行、列链表的头指针向量 
	OrthogonalNode<T>** m_rowHead;
	OrthogonalNode<T>** m_colHead;
	// 稀疏矩阵的行数、列数、非零元素的个数 
	int m_rowLength, m_colLength, m_length;
public:
	OrthogonalList(int rowLength, int colLength, int length);
	OrthogonalList(const OrthogonalList<T>& obj);
	~OrthogonalList();
	void Init();
	void Add(const OrthogonalList<T>& obj);

	void Subtract(const OrthogonalList<T>& obj);
	void Multiply(const OrthogonalList<T>& obj, const OrthogonalList<T>& obj2);

	void Transpose();

	void Insert(int row, int col, T value);
	void Delete(int row, int col);
	void ChangeElement(int row, int col, T value);
	void Print();
};


// 构造函数
template <class T> OrthogonalList<T>::OrthogonalList(int rowLength, int colLength, int length) : m_rowLength(rowLength), m_colLength(colLength), m_length(length)
{
	this->m_rowHead = new OrthogonalNode<T>*[m_rowLength + 1];
	this->m_colHead = new OrthogonalNode<T>*[m_colLength + 1];
	std::memset(this->m_rowHead, 0, sizeof(OrthogonalNode<T>*) * (this->m_rowLength + 1));
	std::memset(this->m_colHead, 0, sizeof(OrthogonalNode<T>*) * (this->m_colLength + 1));
}

// 拷贝构造函数//错的
template <class T>
OrthogonalList<T>::OrthogonalList(const OrthogonalList<T>& obj)
    : m_rowLength(obj.m_rowLength), m_colLength(obj.m_colLength), m_length(obj.m_length)
{
    // 分配新的行链表和列链表头指针数组
    this->m_rowHead = new OrthogonalNode<T>*[m_rowLength + 1];
    this->m_colHead = new OrthogonalNode<T>*[m_colLength + 1];
    
    // 将新链表头指针数组初始化为 NULL
    std::memset(this->m_rowHead, 0, sizeof(OrthogonalNode<T>*) * (this->m_rowLength + 1));
    std::memset(this->m_colHead, 0, sizeof(OrthogonalNode<T>*) * (this->m_colLength + 1));
    
    // 复制稀疏矩阵数据
    for (int i = 1; i <= m_rowLength; i++) {
        OrthogonalNode<T>* current = obj.m_rowHead[i];
        OrthogonalNode<T>* prev = nullptr;
        
        while (current != nullptr) {
            // 复制节点
            OrthogonalNode<T>* newNode = new OrthogonalNode<T>;
            newNode->row = current->row;
            newNode->col = current->col;
            newNode->element = current->element;
            
            // 连接新节点到行链表
            if (prev == nullptr) {
                this->m_rowHead[i] = newNode;
            } else {
                prev->right = newNode;
            }
            
            // 连接新节点到列链表
            if (this->m_colHead[current->col] == nullptr) {
                this->m_colHead[current->col] = newNode;
            } else {
                OrthogonalNode<T>* colCurrent = this->m_colHead[current->col];
                while (colCurrent->down != nullptr) {
                    colCurrent = colCurrent->down;
                }
                colCurrent->down = newNode;
            }
            
            prev = newNode;
            current = current->right;
        }
    }
}
//析构函数
template <class T> OrthogonalList<T>::~OrthogonalList()
{
	for (int i = 0; i <= this->m_rowLength; i++)
	{
		if (this->m_rowHead[i] != NULL)
		{
			OrthogonalNode<T>* p = this->m_rowHead[i];
			while (p != NULL)
			{
				OrthogonalNode<T>* q = p->right;
				delete p; p = q; q = NULL;
			}
			p = NULL;
		}
	}
	delete[] m_rowHead;
	this->m_rowHead = NULL;
	delete[] m_colHead;
	this->m_colHead = NULL;
}


// 初始化稀疏矩阵
template <class T> void OrthogonalList<T>::Init()
{
	int m, n;
	T value;
	for (int i = 0; i < this->m_length; i++)
	{
		std::cin >> m >> n >> value;
		OrthogonalNode<T>* p = new OrthogonalNode<T>;
		// 生成节点
		p->row = m;
		p->col = n;
		p->element = value;
		if (this->m_rowHead[m] == NULL)
		{
			this->m_rowHead[m] = p;
			p->right = NULL;
		}
		else { // 寻找行表中的插入位置
			OrthogonalNode<T>* q;
			q = this->m_rowHead[m];
			while (q->right != NULL && q->right->col < n)
			{
				q = q->right;
			}
			p->right = q->right;
			q->right = p; // 完成插入 
		}
		if (this->m_colHead[n] == NULL)
		{
			this->m_colHead[n] = p;
			p->down = NULL;
		}
		else { // 寻找行表中的插入位置 
			OrthogonalNode<T>* q;
			q = this->m_colHead[n];
			while (q->down != NULL && q->down->row < m)
			{
				q = q->down;
			}
			p->down = q->down;
			q->down = p;
			// 完成插入 
		}
	}
}


// 加法将list2 加到 list1 中 
template <class T>
void OrthogonalList<T>::Add(const OrthogonalList<T>& list)
{
	int i = 0, k = 0; OrthogonalNode<T>* p1, * p2, * tmp;
	while (i <= this->m_rowLength)
	{
		if (this->m_rowHead[i] != NULL && list.m_rowHead[i] != NULL)
		{
			p1 = this->m_rowHead[i];
			p2 = list.m_rowHead[i];
			while (p1 != NULL && p2 != NULL)
			{
				if (p1->col == p2->col)
				{
					int sum = p1->element + p2->element;
					tmp = p1->right;
					// 如果sum!=0，那么就调用“ChangeElement”函数来改变row行，col列的值 
					if (sum != 0)
					{
						this->ChangeElement(p1->row, p1->col, sum);
					}
					// 如果sum==0，那么就调用“Delete”函数来删除row行，col列处的结点 
					else
					{
						this->Delete(p1->row, p1->col);
					}
					p1 = tmp;
					p2 = p2->right;
				}
				else if (p1->col < p2->col)
				{
					p1 = p1->right;
				}
				// 如果是list有，this->list没有的，则将list的相应地方的节点复制并插入到this->list中的row行col列中去 
				else
				{
					this->Insert(p2->row, p2->col, p2->element);
					p2 = p2->right;
				}
			} // 额外的处理
			if (p2 != NULL)
			{
				do
				{
					this->Insert(p2->row, p2->col, p2->element);
					p2 = p2->right;
				} while (p2 != NULL);
			}
		}
		else if (this->m_rowHead[i] == NULL && list.m_rowHead[i] == NULL) {}
		else if (this->m_rowHead[i] != NULL) {}
		else
		{
			p2 = list.m_rowHead[i];
			do
			{
				this->Insert(p2->row, p2->col, p2->element);
				p2 = p2->right;
			} while (p2 != NULL);
		}
		i++;
	}
}

//删除
template <class T> void OrthogonalList<T>::Delete(int row, int col)
{
	OrthogonalNode<T>* p; OrthogonalNode<T>* q;
	if (this->m_rowHead[row] == NULL)
	{
		std::cout << "Delete Error!" << std::endl;
	}
	else
	{
		p = this->m_rowHead[row];
		if (p->col == col)
		{
			this->m_rowHead[row] = p->right;
		}
		else
		{
			while (p->right->col != col)
			{
				p = p->right;
			}
			q = p->right;
			p->right = q->right;
		}
	}
	if (this->m_colHead[col] == NULL)
	{
		std::cout << "Delete Error!" << std::endl;
	}
	else
	{
		p = this->m_colHead[col];
		if (p->row == row)
		{
			q = p; this->m_colHead[col] = p->down;
			delete q; q = NULL;
		}
		else
		{
			while (p->down->row != row)
			{
				p = p->down;
			}
			q = p->down;
			p->down = q->down;
			delete q; q = NULL;
		}
	}
}
//修改
template <class T> void OrthogonalList<T>::ChangeElement(int row, int col, T value)
{
	OrthogonalNode<T>* p; p = this->m_rowHead[row];
	while (p->col != col)
	{
		p = p->right;
	}
	p->element = value;
}

//插入
template <class T> void OrthogonalList<T>::Insert(int row, int col, T value)
{
	OrthogonalNode<T>* p = new OrthogonalNode<T>; // 生成节点 
	p->row = row;
	p->col = col;
	p->element = value;
	if (this->m_rowHead[row] == NULL)
	{
		this->m_rowHead[row] = p; p->right = NULL;
	}
	else
	{ // 寻找行表中的插入位置 
		OrthogonalNode<T>* q;
		q = this->m_rowHead[row]; // 如果第一个就为 p 的话就插入
		if (p->col < q->col)
		{
			p->right = q; this->m_rowHead[row] = p;
		}
		else
		{
			while (q->right != NULL && q->right->col < col)
			{
				q = q->right;
			}
			p->right = q->right;
			q->right = p; // 完成插入 
		}
	}
	if (this->m_colHead[col] == NULL)
	{
		this->m_colHead[col] = p; p->down = NULL;
	}
	else { // 寻找行表中的插入位置 
		OrthogonalNode<T>* q;
		q = this->m_colHead[col];
		if (p->row < q->row)
		{
			p->down = q;
			this->m_colHead[col] = p;
		}
		else
		{
			while (q->down != NULL && q->down->row < row)
			{
				q = q->down;
			}
			p->down = q->down;
			q->down = p; // 完成插入 
		}
	}
	this->m_length++;
}


//输出
template <class T>
void OrthogonalList<T>::Print() {
	for (int i = 1; i <= this->m_rowLength; i++) {
		for (int j = 1; j <= this->m_colLength; j++) {
			OrthogonalNode<T>* p = this->m_rowHead[i];
			bool found = false;

			while (p != nullptr) {
				if (p->col == j) {
					std::cout << p->element << " ";
					found = true;
					break;
				}
				p = p->right;
			}

			if (!found) {
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
}

//矩阵相减
template <class T>
void OrthogonalList<T>::Subtract(const OrthogonalList<T>& list)
{
	int i = 0, k = 0;
	OrthogonalNode<T>* p1, * p2, * tmp;

	while (i <= this->m_rowLength)
	{
		if (this->m_rowHead[i] != NULL && list.m_rowHead[i] != NULL)
		{
			p1 = this->m_rowHead[i];
			p2 = list.m_rowHead[i];

			while (p1 != NULL && p2 != NULL)
			{
				if (p1->col == p2->col)
				{
					int diff = p1->element - p2->element;
					tmp = p1->right;

					// 使用 ChangeElement 方法更新当前元素的值
					this->ChangeElement(p1->row, p1->col, diff);

					p1 = tmp;
					p2 = p2->right;
				}
				else
					if (p1->col < p2->col)
					{
						p1 = p1->right;
					}
					else
					{
						// 在 list 中有，而 this->list 没有的位置，将 list 中的相应位置的元素取反并插入到 this->list 的 (row, col) 位置
						this->Insert(p2->row, p2->col, -p2->element);
						p2 = p2->right;
					}
			}

			// 处理 list 中多余的节点
			if (p2 != NULL)
			{
				do
				{
					// list 中多余的元素需要取反再插入
					this->Insert(p2->row, p2->col, -p2->element);
					p2 = p2->right;
				} while (p2 != NULL);
			}
		}
		else if (this->m_rowHead[i] == NULL && list.m_rowHead[i] == NULL)
		{
			// 两个矩阵的当前行都没有非零元素，无需处理
		}
		else if (this->m_rowHead[i] != NULL)
		{
			// this->list 有非零元素，但 list 没有，无需处理
		}
		else
		{
			// list 有非零元素，但 this->list 没有，直接将 list 的元素取反并插入到 this->list 中
			p2 = list.m_rowHead[i];
			do
			{
				// list 中多余的元素需要取反再插入
				this->Insert(p2->row, p2->col, -p2->element);
				p2 = p2->right;
			} while (p2 != NULL);
		}
		i++;
	}
}

// Multiply 用于两个矩阵相乘
template <class T>
void OrthogonalList<T>::Multiply(const OrthogonalList<T>& matrix1, const OrthogonalList<T>& matrix2)
{

	if (matrix1.m_colLength != matrix2.m_rowLength)
	{
		std::cout << "矩阵无法相乘，列数与行数不匹配。" << std::endl;
		return;
	}

	//创建一个新的稀疏矩阵用于存储相乘的结果
	OrthogonalList<T> result(matrix1.m_rowLength, matrix2.m_colLength, 0);

	for (int i = 1; i <= matrix1.m_rowLength; i++)
	{
		for (int j = 1; j <= matrix2.m_colLength; j++)
		{
			T sum = 0;
			OrthogonalNode<T>* p1 = matrix1.m_rowHead[i];
			OrthogonalNode<T>* p2 = matrix2.m_colHead[j];

			while (p1 != nullptr && p2 != nullptr)
			{
				if (p1->col == p2->row)
				{
					sum += p1->element * p2->element;
					p1 = p1->right;
					p2 = p2->down;
				}
				else if (p1->col < p2->row)
				{
					p1 = p1->right;
				}
				else
				{
					p2 = p2->down;
				}
			}
			if (sum != 0)
			{
				result.Insert(i, j, sum);
			}
		}
	}

	std::cout << "两个矩阵相乘的结果：" << std::endl;
	result.Print();

}


// Transpose 用于矩阵转置
template <class T>
void OrthogonalList<T>::Transpose()
{
	OrthogonalList<T> transposed(m_colLength, m_rowLength, m_length);

	for (int i = 1; i <= m_rowLength; i++)
	{
		OrthogonalNode<T>* p = m_rowHead[i];
		while (p != nullptr)
		{
			transposed.Insert(p->col, p->row, p->element);
			p = p->right;
		}
	}

	std::cout << "转置后的矩阵：" << std::endl;
	transposed.Print();

}

template <class T>
void operator+(OrthogonalList<T>& list1, const OrthogonalList<T>& list2)
{
	list1.Add(list2);  // 调用 Add 函数将 list2 加到 list1 中
}

template <class T>
void operator-(OrthogonalList<T>& list1, const OrthogonalList<T>& list2)
{
	list1.Subtract(list2);  // 调用 Subtract 函数将 list2 从 list1 中减去
}

template <class T>
void operator*( OrthogonalList<T>& matrix1, const OrthogonalList<T>& matrix2)
{
	matrix1.Multiply(matrix1, matrix2);  // 调用 Multiply 函数进行矩阵相乘
}

//重载输入
template <class T>
std::istream& operator>>(std::istream& input, OrthogonalList<T>& matrix) 
{
	matrix.Init();
	return input;
}
//重载输出
template <class T>
std::ostream& operator<<(std::ostream& output, OrthogonalList<T>& matrix)
{
	matrix.Print();
	return output;
}
#endif 

int main()
{
	int flag;
	int row, col, t1, t2;
	std::cout << "请输入要进行的操作：（0+，1-,2*,3转置)" << std::endl;
	std::cin >> flag;

	switch (flag)
	{

	case 0:
	{
		std::cout << "请输入要相加的两个矩阵的维度和非零元素的数量：" << std::endl;
		std::cout << "行数：";
		std::cin >> row;
		std::cout << "列数：";
		std::cin >> col;
		std::cout << "第一个矩阵（t1）的非零元素数量：";
		std::cin >> t1;
		std::cout << "第二个矩阵（t2）的非零元素数量：";
		std::cin >> t2;
		OrthogonalList<int> list1(row, col, t1);
		OrthogonalList<int> list2(row, col, t2);
		std::cout << "请输入第一个矩阵（t1）的非零元素：" << std::endl;
		std::cin >> list1;
		std::cout << "请输入第二个矩阵（t2）的非零元素：" << std::endl;
		std::cin >> list2;

		std::cout << "输入的第一个矩阵是：" << std::endl;
		std::cout << list1;
		std::cout << "输入的第二个矩阵是：" << std::endl;
		std::cout << list2;

		std::cout << "相加后的矩阵：" << std::endl;
		list1+list2;
		std::cout << list1;

		break;

	}

	case 1:
	{
		std::cout << "请输入要相减矩阵的维度和非零元素的数量：" << std::endl;
		std::cout << "行数：";
		std::cin >> row;
		std::cout << "列数：";
		std::cin >> col;
		std::cout << "第一个矩阵（t1）的非零元素数量：";
		std::cin >> t1;
		std::cout << "第二个矩阵（t2）的非零元素数量：";
		std::cin >> t2;

		OrthogonalList<int> list3(row, col, t1);
		OrthogonalList<int> list4(row, col, t2);
		std::cout << "请输入第一个矩阵（t1）的非零元素：" << std::endl;
		std::cin >> list3;
		std::cout << "请输入第二个矩阵（t2）的非零元素：" << std::endl;
		std::cin >> list4;
		std::cout << "输入的第一个矩阵是：" << std::endl;
		std::cout << list3;
		std::cout << "输入的第二个矩阵是：" << std::endl;
		std::cout << list4;

		std::cout << "相减后的矩阵：" << std::endl;
		list3-list4;
		std::cout << list3;

		break;
	}
	case 2:
	{// 矩阵相乘操作
		std::cout << "请输入要相乘的两个矩阵的维度和非零元素的数量：" << std::endl;
		std::cout << "第一个矩阵：" << std::endl;
		std::cout << "行数：";
		std::cin >> row;
		std::cout << "列数：";
		std::cin >> col;
		std::cout << "非零元素数量：";
		std::cin >> t1;
		OrthogonalList<int> matrix1(row, col, t1);
		std::cout << "请输入第一个矩阵的非零元素：" << std::endl;
		std::cin >> matrix1;

		std::cout << "第二个矩阵：" << std::endl;
		std::cout << "行数：";
		std::cin >> row;
		std::cout << "列数：";
		std::cin >> col;
		std::cout << "非零元素数量：";
		std::cin >> t2;
		OrthogonalList<int> matrix2(row, col, t2);
		std::cout << "请输入第二个矩阵的非零元素：" << std::endl;
		std::cin >> matrix2;

		std::cout << "输入的第一个矩阵是：" << std::endl;
		std::cout << matrix1;
		std::cout << "输入的第二个矩阵是：" << std::endl;
		std::cout << matrix2;
		// 执行矩阵相乘操作
		matrix1*matrix2;

		break;
	}

	case 3:
	{// 矩阵转置操作
		std::cout << "请输入要转置的矩阵的维度和非零元素数量：" << std::endl;
		std::cout << "矩阵：" << std::endl;
		std::cout << "行数：";
		std::cin >> row;
		std::cout << "列数：";
		std::cin >> col;
		std::cout << "非零元素数量：";
		std::cin >> t1;
		OrthogonalList<int> matrix(row, col, t1);
		std::cout << "请输入矩阵的非零元素：" << std::endl;
		std::cin >> matrix;

		std::cout << "输入的矩阵是：" << std::endl;
		std::cout << matrix;

		// 执行矩阵转置操作并打印结果
		matrix.Transpose();
		break;
	}

	}

	return 0;
}