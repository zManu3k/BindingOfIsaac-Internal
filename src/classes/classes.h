#ifndef CLASSES_H
#define CLASSES_H

#include <cstdint>

namespace IsaacRepetance
{
	class Entity_Player;
	class Entity_NPC;
	class Entity_Bomb;
	class Entity_Effect;
	class Weapon_Tears;
	class GameEngine;
	class GridEntity_Door;
}

namespace KAGE::Graphics
{
	class ImagePng;
	class ProceduralImagePlatform;
}

class Room;

class IsaacRepetance::Entity_Player
{
public:
	char pad_0004[108]; //0x0004
	char *walk_direction; //0x0070
	char pad_0074[12]; //0x0074
	int32_t isMoving; //0x0080
	char pad_0084[12]; //0x0084
	char *head_direction; //0x0090
	char pad_0094[512]; //0x0094
	float posX; //0x0294
	float posY; //0x0298
	char pad_029C[28]; //0x029C
	float movingX; //0x02B8
	float movingY; //0x02BC
	char pad_02C0[4048]; //0x02C0
	uint32_t max_health; //0x1290
	uint32_t health; //0x1294 (max 10)
	uint32_t eternal_heart; //0x1298 (max 1)
	uint32_t soul_hearts; //0x129C (max 38)
	char pad_12A0[12]; //0x12A0
	uint32_t keys; //0x12AC
	char pad_12B0[4]; //0x12B0
	uint32_t bomb; //0x12B4 (max 99)
	int32_t coins; //0x12B8 (max 99)
	char pad_12BC[12]; //0x12BC
	int32_t action_maybe; //0x12C8
	char pad_12CC[96]; //0x12CC
	class IsaacRepetance::Weapon_Tears *Weapon_Tears; //0x132C
	char pad_1330[120]; //0x1330
	float shots_delay; //0x13A8 0 is the best
	float bullet_speed; //0x13AC 5 is the best
	char pad_13B0[4]; //0x13B0
	uint32_t shots_fired; //0x13B4
	float bullet_damage; //0x13B8 everything is good
	char pad_13BC[168]; //0x13BC
	class IsaacRepetance::Entity_Player *_this; //0x1464
	char pad_1468[68]; //0x1468
	float movement_speed; //0x14AC
	char pad_14B0[20]; //0x14B0
	uint32_t active_item; //0x14C4
	uint32_t active_item_charge; //0x14C8
	char pad_14CC[120]; //0x14CC
	uint32_t bomb_cooldown; //0x1544
	char pad_1548[140]; //0x1548
	class IsaacRepetance::Entity_Bomb *Entity_Bomb; //0x15D4
	char pad_15D8[2608]; //0x15D8

	virtual void SaveAndExit();
	virtual void InitializeWorld();
	virtual void UpdateCoords();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void EnemyShoots();
	virtual void InitPlayerManagerMaybe();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
}; //Size: 0x2008
static_assert(sizeof(IsaacRepetance::Entity_Player) == 0x2008);

class IsaacRepetance::GameEngine
{
public:
	char pad_0000[98704]; //0x0000
	class Room *room; //0x18190
	char pad_18194[956236]; //0x18194
	class KAGE::Graphics::ProceduralImagePlatform *ProceduralImagePlatform; //0x1018E0
	char pad_1018E4[4]; //0x1018E4
	class KAGE::Graphics::ImagePng *ImagePng; //0x1018E8
	char pad_1018EC[1828]; //0x1018EC
	class IsaacRepetance::Entity_Player *Entity_Player; //0x102010
	char pad_102014[40]; //0x102014
	uint32_t game_status; //0x10203C
	char pad_102040[8]; //0x102040
	uint32_t display_speed; //0x102048
	uint32_t display_bullet_speed; //0x10204C
	uint32_t display_damage; //0x102050
	char pad_102054[8]; //0x102054
	uint32_t display_luck; //0x10205C
	char pad_102060[60]; //0x102060
	char *game_status_string; //0x10209C
	char pad_1020A0[1216]; //0x1020A0
	char *showtext_string; //0x102560
	char pad_102564[2840]; //0x102564
}; //Size: 0x10307C
static_assert(sizeof(IsaacRepetance::GameEngine) == 0x10307C);

class IsaacRepetance::Weapon_Tears
{
public:
	class IsaacRepetance::Entity_Player *Entity_Player; //0x0004
	char pad_0008[4]; //0x0008
	float is_shooting; //0x000C
	char pad_0010[36]; //0x0010
	uint32_t total_shots; //0x0034
	char pad_0038[1608]; //0x0038

	virtual void SaveAndExitMaybe();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void XorEax();
	virtual void Function10();
	virtual void Return0();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
}; //Size: 0x0680
static_assert(sizeof(IsaacRepetance::Weapon_Tears) == 0x680);

class IsaacRepetance::Entity_Bomb
{
public:
	char pad_0004[28]; //0x0004
	uint32_t total_damage; //0x0020
	char pad_0024[284]; //0x0024

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0140
static_assert(sizeof(IsaacRepetance::Entity_Bomb) == 0x140);

class KAGE::Graphics::ProceduralImagePlatform
{
public:
	char pad_0004[128]; //0x0004

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0084
static_assert(sizeof(KAGE::Graphics::ProceduralImagePlatform) == 0x84);

class KAGE::Graphics::ImagePng
{
public:
	char pad_0004[64]; //0x0004

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0044
static_assert(sizeof(KAGE::Graphics::ImagePng) == 0x44);

class IsaacRepetance::Entity_NPC
{
public:
	char pad_0004[4]; //0x0004
	uint32_t default_value; //0x0008
	uint32_t replace_if_hit; //0x000C
	uint32_t move_if_hit; //0x0010
	char pad_0014[40]; //0x0014
	char *entity_name; //0x003C
	char pad_0040[48]; //0x0040
	char *movement_type; //0x0070
	char pad_0074[20]; //0x0074
	uint32_t action_shot; //0x0088
	char pad_008C[520]; //0x008C
	float pos_x; //0x0294
	float pos_y; //0x0298
	char pad_029C[60]; //0x029C
	float current_health; //0x02D8
	float initial_health; //0x02DC
	char pad_02E0[13668]; //0x02E0

	virtual void Function0();
	virtual void Function1();
	virtual void UpdateCoords();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void onEntityDamaged();
	virtual void onEntityKilled();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function10();
}; //Size: 0x3844
static_assert(sizeof(IsaacRepetance::Entity_NPC) == 0x3844);

class Room
{
public:
	char pad_0000[4700]; //0x0000
	uint32_t EntityList; //0x125C
	char pad_1260[100]; //0x1260
	uint32_t EntityNPC_Size; //0x12C4
	char pad_12C8[4284]; //0x12C8
}; //Size: 0x2384
static_assert(sizeof(Room) == 0x2384);

class IsaacRepetance::Entity_Effect
{
public:
	char pad_0004[60]; //0x0004

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0040
static_assert(sizeof(IsaacRepetance::Entity_Effect) == 0x40);

class IsaacRepetance::GridEntity_Door
{
public:
	char pad_0000[1088]; //0x0000
}; //Size: 0x0440
static_assert(sizeof(IsaacRepetance::GridEntity_Door) == 0x440);

#endif //CLASSES_H
