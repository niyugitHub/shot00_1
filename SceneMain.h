#pragma once

#include "player.h"
#include "enemy.h"
#include "shot.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();

	// ショットを打つ
	bool createShot(Vec2 pos, bool isPlayer);
	
private:
	// ショットの最大数
	static constexpr int kShotMax = 64;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// 敵
	Enemy m_enemy;
	// ショット
	Shot m_shot[kShotMax];
};