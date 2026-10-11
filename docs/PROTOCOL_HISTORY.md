# Protocol history

The wire protocol version lives in `src/netproto/Wire.h` (`PROTOCOL_VERSION`).
It is checked at handshake; a mismatch is rejected (no back-compat). Every bump
gets a one-line entry here, newest at the bottom. Planned numbers are reserved
so parallel integration lines do not collide.

| Version | Change |
|---|---|
| 55 | Base fork point: upstream KenshiCoop v0.51 (`5a761e19`). |
| 56 | PR #70 (jayceslesar): save-native ground pickup notice (`PKT_NATIVE_TAKEN`), fixes upstream #44. |
| 57 | PR #75 (BorjaAres): host-validated production recipe intents (`PKT_PROD_INTENT` = 50; tag 49 was taken by `PKT_NATIVE_TAKEN`). |
| 58 | PR #76 (BorjaAres): host-validated door open/lock intents (`PKT_DOOR_INTENT` = 51; series shifted by one after tag 49 collision). |
| 59 | PR #78 (BorjaAres): host-canonical bed/cage occupancy intents (`PKT_FURNITURE` = 52; same one-tag shift). |
| 60 | PR #79 (BorjaAres): host-canonical construction place/remove intents (`PKT_BUILD_INTENT` = 53; same one-tag shift). |
| 61 | PR #80 (BorjaAres): inventory save fence over owner-authored state (`PKT_INV_SAVE_FENCE` = 54; same one-tag shift). |
| 62 | PR #18 (zeroit789): host-authoritative bounty/crime sync (`PKT_BOUNTY` = 55; the PR's tag 42 was taken by `PKT_COMBAT_HIT`). |
| 63 | PR #28 (ChainsLunatic, extraction): character name in `SpawnInfoPacket` + animal age in `StatsPacket` (new fields only, no new tags). |
| 64 | PR #36 (jbaxter91): join assassination knockout report via a `MedicalSystem::knockout` detour (`COMBAT_HIT_KNOCKOUT` flag + `koSkill` field on `CombatHitPacket`, size 37→42; no new tags). Number 64 was reserved for PR #35, which merged empty (nested backpack sync already covered upstream), so 64 passes to #36. |

| 65 | **Merge (atimal04/TokelaCoop):** TokelaCoop v0.54 line (its own 56 = active-mod list `PKT_MODLIST`, 57 = v0.54 own-characters guard + squad-owner ledger) merged with this KenshiDuo line (56-64). The two lines both used tag 49, so `PKT_MODLIST` moves to tag **56**; every KenshiDuo tag keeps its number. 65 refuses both parents (57 and 64) at handshake. |
| 66 | Join-to-host storage add intent (`PKT_STORE_ADD` = 57) for settled additions to host-censused containers; host validates and adds the requested quantity, and its protocol-34 snapshot publishes the result. Census snapshots carry `INV_FLAG_STORE` so joins can distinguish stores from ordinary host inventories. |

## Planned (reserved, not yet merged)

| Version | Change |
|---|---|
