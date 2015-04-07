#ifndef __Queue_H__
#define __Queue_H__

#define NULL 0

// Contains items from single linked list
template<class TYPE>
struct QueueItem
{
	TYPE               data;
	QueueItem<TYPE>*   next;

	inline QueueItem(const TYPE& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~QueueItem()
	{}
};

//Manages a double linked list
template<class TYPE>
class Queue
{

public:

	QueueItem<TYPE>*   start;
	QueueItem<TYPE>*   end;

private:

	unsigned int  size;

public:

	//Constructor
	inline Queue()
	{
		start = end = NULL;
		size = 0;
	}

	//Destructor
	~Queue()
	{
	}

	void push(const TYPE& item)
	{
		QueueItem<TYPE>*   p_data_item;
		p_data_item = new QueueItem < TYPE >(item);

		if (start == NULL)
		{
			start = end = p_data_item;
		}
		else
		{
			QueueItem<TYPE>*   tmp;
			for (unsigned int i = 1; i < size; i++)
				tmp->next = tmp;
			tmp->next = p_data_item;
			end = p_data_item;
		}
	}

	//Deletes an item from the list
	TYPE pop(QueueItem<TYPE>* item)
	{
		if (item == start)
		{
			if (item->next != NULL)
			{
				start = item->next;
				TYPE valueToReturn = item.data;
				delete item;
				return valueToReturn;
			}
			else
			{
				start = NULL;
				end = NULL;
				TYPE valueToReturn = item.data;
				delete item;
				return valueToReturn;
			}
		}
		
		else
		{
			return 0;
		}
	}

};
#endif