#pragma once
#include "Engine/GameObject.h"

//戦車(上)を管理するクラス
class Cannon : public GameObject
{
	const float SWING_SPEED = 3.0f; //左右の回転スピード
	int hModel_;    //モデル番号
	int hSound_;    //サウンド番号
public:
	//コンストラクタ
	Cannon(GameObject* parent);

	//デストラクタ
	~Cannon();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//地面のモデル番号を取得
	int GetModelHandle() { return hModel_; }
};
