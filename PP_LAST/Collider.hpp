#pragma once
bool Collider_bullet(float box_x, float box_y, float player_x, float player_y)
{
	bool hit[2];

	//Player = left top----------------------

	// enemy left bottom
	if (box_x < player_x && box_y < player_y) {
		hit[0] = true;
	}
	else hit[0] = false;

	// enemy right top
	if (0.1f + box_x > player_x && 0.1f + box_y > player_y) {
		hit[1] = true;
	}
	else hit[1] = false;

	
	if (hit[0] && hit[1])
	{
		std::cout << "?浹";
		return true;
	}
	return false;
}

bool Collider(float box_x, float box_y, float player_x, float player_y)
{
	bool hit[8];

	//Player = left top----------------------

	// enemy left bottom
	if (box_x < player_x && box_y < 0.1f + player_y) {
		hit[0] = true;
}
	else hit[0] = false;

	// enemy right top
	if (0.1f + box_x > player_x && 0.1f + box_y > 0.1f + player_y) {
		hit[1] = true;
	}
	else hit[1] = false;

	//Player = left bottom----------------------
	if (box_x < player_x && box_y < player_y) {
		hit[2] = true;
	}
	else hit[2] = false;

	// enemy right top
	if (0.1f + box_x > player_x && 0.1f + box_y > player_y) {
		hit[3] = true;
	}
	else hit[3] = false;

	//Player = right top----------------------
	if (box_x < 0.1f + player_x && box_y < 0.1f + player_y) {
		hit[4] = true;
	}
	else hit[4] = false;

	// enemy right top
	if (0.1f + box_x > 0.1f + player_x && 0.1f + box_y > 0.1f + player_y) {
		hit[5] = true;
	}
	else hit[5] = false;


	//Player = right bottom----------------------
	if (box_x < 0.1f + player_x && box_y < player_y) {
		hit[6] = true;
	}
	else hit[6] = false;

	// enemy right top
	if (0.1f + box_x > 0.1f + player_x && 0.1f + box_y > player_y) {
		hit[7] = true;
	}
	else hit[7] = false;



	if ((hit[0] && hit[1]) || (hit[2] && hit[3]) || (hit[4] && hit[5]) || (hit[6] && hit[7]))
	{
		std::cout << "?浹";
		return true;
	}
	return false;
}
