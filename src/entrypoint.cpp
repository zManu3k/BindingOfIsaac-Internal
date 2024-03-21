#include <cstdio>
#include <print>
#include <format>
#include <thread>
#include <typeinfo>

#include <Windows.h>

#include "classes/classes.h"
#include "hooks/wndproc.h"

void run( const HMODULE hModule ) {
    AllocConsole( );
    FILE* pFile;
    freopen_s( &pFile, "CONOUT$", "w", stdout );

    // Create wndproc hook ( to get pressed keys instead of GetAsyncKeyState( ) )
    wndproc::originalWndProc = SetWindowLongPtr( FindWindowA( nullptr, "Binding of Isaac: Repentance" ), GWLP_WNDPROC,
                                                 reinterpret_cast<LONG_PTR>( wndproc::WndProc ) );

    // Get moduleBase ( isaac-ng.exe ) and find GameEngine
    const auto moduleBase = reinterpret_cast<uintptr_t>( GetModuleHandle( "isaac-ng.exe" ) );
    const auto* game = *reinterpret_cast<IsaacRepetance::GameEngine**>( moduleBase + 0x7FF59C );

    // Print addresses
    std::println( "[+] ModuleBase: [ 0x{:X} ]", moduleBase );
    std::println( "[+] Game: [ 0x{:X} ]", reinterpret_cast<uintptr_t>( game ) );
    std::println( "[+] Entity_Player: [ 0x{:X} ]", reinterpret_cast<uintptr_t>( game->Entity_Player ) );
    std::println( "[+] Weapon_Tears: [ 0x{:X} ]", reinterpret_cast<uintptr_t>( game->Entity_Player->Weapon_Tears ) );
    std::println( "[+] EntityList: [ 0x{:X} ( size: {:} ) ]", game->room->EntityList, game->room->EntityNPC_Size );

    // cheat loop
    while( !wndproc::keyState[ VK_F8 ] ) {

        if( !game->Entity_Player ) continue;

        // modify fields value
        game->Entity_Player->max_health = 10;
        game->Entity_Player->health = 10;
        game->Entity_Player->soul_hearts = 38;
        game->Entity_Player->bomb = 99;
        game->Entity_Player->keys = 99;
        game->Entity_Player->coins = 99;
        game->Entity_Player->active_item_charge = 1000;
        game->Entity_Player->bomb_cooldown = 0;
        game->Entity_Player->movement_speed = 3.f;
        game->Entity_Player->shots_delay = 0.0f;
        game->Entity_Player->bullet_speed = 5.f;
        game->Entity_Player->bullet_damage = 100.f;

        if( wndproc::keyState[ VK_F3 ] ) {
            // iterate the entitylist ( i = 1 because we want skip Entity_Player ( at pos 0 ) )
            for( size_t i = 1; i <= game->room->EntityNPC_Size; i++ ) {
                IsaacRepetance::Entity_NPC* npc = *reinterpret_cast<IsaacRepetance::Entity_NPC**>( game->room->EntityList + i * 4 );

                // call method from vtable to force entity kill
                npc->onEntityKilled( );

                std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
            }
        }

        std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
    }

    // unhook wndproc
    SetWindowLongPtr( FindWindowA( nullptr, "Binding of Isaac: Repentance" ), GWLP_WNDPROC, wndproc::originalWndProc );

    std::println( "\nYou can now close console!" );

    FreeConsole( );
    FreeLibraryAndExitThread( hModule, 0 );
}

BOOL WINAPI DllMain(
    HMODULE hModule, // handle to DLL module
    DWORD fdwReason, // reason for calling function
    LPVOID lpvReserved ) // reserved
{
    // check for attach reason ( we only need DLL_PROCESS_ATTACH )
    if( fdwReason == DLL_PROCESS_ATTACH )
        CreateThread( nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( run ), hModule, 0, nullptr );

    return TRUE;
}
