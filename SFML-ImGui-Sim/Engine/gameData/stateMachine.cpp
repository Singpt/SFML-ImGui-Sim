#include "stateMachine.h"

void stateMachine::AddState(StateRef newState, bool isReplacing)	//查看替换权，允许添加，将智能指针指向新状态
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;

	this->_newState = std::move(newState);	//转移状态
}

void stateMachine::RemoveState()	//允许替换
{
	this->_isRemoving = true;
}

void stateMachine::ProcessStateChanges()		//处理状态变化过程
{
	if (this->_isRemoving && !this->_states.empty())		//如果允许替换并且状态栈不为空
	{
		this->_states.pop();					//弹出栈顶状态

		if (!this->_states.empty())				//如果栈不空
		{
			this->_states.top()->Resume();		//重新开始
		}

		this->_isRemoving = false;			//不允许移除
	}

	if (this->_isAdding)			//如果允许添加且栈不空
	{
		if (!this->_states.empty())
		{
			if (this->_isReplacing)			//且允许替换
			{
				this->_states.pop();		//弹出栈顶状态
			}
			else       //不允许替换
			{
				this->_states.top()->Pause();	//暂停
			}
		}

		this->_states.push(std::move(this->_newState));		//将新状态转移到栈中，避免拷贝
		this->_states.top()->Init();		//初始化新状态
		this->_isAdding = false;			//不允许添加
	}
}

StateRef& stateMachine::GetActiveState()		//获取当前状态
{
	return this->_states.top();			//返回当天栈顶状态
}