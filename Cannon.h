#pragma once
#include "Engine/GameObject.h"

//��Ԃ̏㕔�����Ǘ�����N���X
class Cannon : public GameObject
{
	const float SWING_SPEED = 3.0f; //���E�̉�]�X�s�[�h
	int hModel_;    //���f���ԍ�
public:
	//�R���X�g���N�^
	Cannon(GameObject* parent);

	//�f�X�g���N�^
	~Cannon();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�n�ʂ̃��f���ԍ����擾
	int GetModelHandle() { return hModel_; }
};
