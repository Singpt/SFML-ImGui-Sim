#include "stateMachine.h"

void stateMachine::AddState(StateRef newState, bool isReplacing)	//�鿴�滻Ȩ��������ӣ�������ָ��ָ����״̬
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;

	this->_newState = std::move(newState);	//ת��״̬
}

void stateMachine::RemoveState()	//�����滻
{
	this->_isRemoving = true;
}

void stateMachine::ProcessStateChanges()		//����״̬�仯����
{
	if (this->_isRemoving && !this->_states.empty())		//��������滻����״̬ջ��Ϊ��
	{
		this->_states.pop();					//����ջ��״̬

		if (!this->_states.empty())				//���ջ����
		{
			this->_states.top()->Resume();		//���¿�ʼ
		}

		this->_isRemoving = false;			//�������Ƴ�
	}

	if (this->_isAdding)			//������������ջ����
	{
		if (!this->_states.empty())
		{
			if (this->_isReplacing)			//�������滻
			{
				this->_states.pop();		//����ջ��״̬
			}
			else       //�������滻
			{
				this->_states.top()->Pause();	//��ͣ
			}
		}

		this->_states.push(std::move(this->_newState));		//����״̬ת�Ƶ�ջ�У����⿽��
		this->_states.top()->Init();		//��ʼ����״̬
		this->_isAdding = false;			//���������
	}
}

StateRef& stateMachine::GetActiveState()		//��ȡ��ǰ״̬
{
	return this->_states.top();			//���ص���ջ��״̬
}