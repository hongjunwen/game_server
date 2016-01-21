/*
 *  Created on: Dec 16, 2015
 *      Author: zhangyalei
 */


#ifndef GAME_CLIENT_MESSAGER_H_
#define GAME_CLIENT_MESSAGER_H_

#include "Msg_Define.h"
#include "Block_Buffer.h"
#include "Game_Player.h"

class Game_Client_Messager {
public:
	static Game_Client_Messager *instance(void);

	int process_block(Block_Buffer &buf);
	int process_init_block(int gate_cid, int player_cid, int msg_id, Block_Buffer &buf);
	int process_client_block(int msg_id, Block_Buffer &buf, Game_Player *player);

	int process_bag_block(int msg_id, Block_Buffer &buf, Game_Player *player);
	int process_mail_block(int msg_id, Block_Buffer &buf, Game_Player *player);

	/// 获取角色信息
	int process_120001(int gate_cid, int player_cid, MSG_120001 &msg);
	/// 创建角色
	int process_120002(int gate_cid, int player_cid, MSG_120002 &msg);
	///gate玩家掉线通知game
	int process_113000(MSG_113000 &msg);

private:
	Game_Client_Messager(void);
	virtual ~Game_Client_Messager(void);
	Game_Client_Messager(const Game_Client_Messager &);
	const Game_Client_Messager &operator=(const Game_Client_Messager &);

private:
	static Game_Client_Messager *instance_;
};

#define GAME_CLIENT_MESSAGER Game_Client_Messager::instance()

#endif /* GAME_CLIENT_MESSAGER_H_ */
