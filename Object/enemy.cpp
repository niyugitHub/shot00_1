#include "DxLib.h"
#include "game.h"
#include "enemy.h"
#include "SceneMain.h"

namespace
{
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
	
	// ショットの生成間隔
	constexpr int kShotInterval = 60;
}

Enemy::Enemy() :
	m_pMain(nullptr),
	m_handle(-1),
	m_shotInterval(kShotInterval),
	m_isExist(false),
	m_pos(),
	m_vec()
{
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth - 80.0f;
	m_pos.y = Game::kScreenHeight / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_isExist = true;
}

void Enemy::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	m_shotInterval--;
	if (m_pMain && m_shotInterval <= 0)
	{
		m_pMain->createShot(m_pos,false);
		m_shotInterval = kShotInterval;
	}
}

void Enemy::draw()
{
	if (!m_isExist) return;
//	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}

float Enemy::getColHeight()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}