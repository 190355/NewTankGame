#pragma once
#include "Engine/GameObject.h"

//�e���Ǘ�����N���X
class Bullet : public GameObject
{
	int hModel_;    //���f���ԍ�
	XMVECTOR move_; //�ړ��x�N�g��
	const float SPEED; //�e�̑���

public:
	//�R���X�g���N�^
	Bullet(GameObject* parent);

	//�f�X�g���N�^
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�e�̔���
	//�����Fposition   ���ˈʒu
	//�����Fdirection  ���˕���
	void Shot(XMVECTOR position, XMVECTOR direction);
};
