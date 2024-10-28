#include "raylib.h"

struct Vec2 {
	float x,y;
	Vec2(float a, float b){
		x = a;
		y = b;
	}
};


int main(void)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_FULLSCREEN_MODE);
    InitWindow(800, 400, "iGen");
	SetTargetFPS(60);

	float scale  = 1;
	int shiftX = 0;
	int shiftY = 0;

	Vec2 point(2,2);

    while (!WindowShouldClose())
    {
		const int height = GetRenderHeight();
		const int width  = GetRenderWidth();
		const int grid_scale = 50 * scale;
		const int grid_width  = width  / (grid_scale);
		const int grid_height = height / (grid_scale);

		{
			if (IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP)){
				shiftY -= 3;
			}
			if (IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN)){
				shiftY += 3;
			}
			if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)){
				shiftX -= 3;
			}
			if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)){
				shiftX += 3;
			}
			if (IsKeyPressed(KEY_O) || IsKeyPressedRepeat(KEY_O)){
				scale += 0.2f;
			}
			if (IsKeyPressed(KEY_I) || IsKeyPressedRepeat(KEY_I)){
				if(scale > 1) scale -= 0.2;
			}
		}

        BeginDrawing();
		{
            ClearBackground(Color {24, 24, 24, 255});

			const int x_axis = grid_width / 2;
			const int y_axis = grid_height / 2;
			const int midpointX = width/2 - shiftX;
			const int midpointY = height/2 + shiftY;

			for (int w = (-grid_width/2) * scale; w <= (grid_width/2) * scale; w++){
				DrawLine(midpointX + w*grid_scale, 0, midpointX + w*grid_scale, height, Color{40,40, 200, 125});
			}

			for (int h = -grid_height/2 * scale; h <= grid_height/2 * scale; h++){
				DrawLine(0, midpointY + h*grid_scale, width, midpointY + h*grid_scale,  Color{40,150, 150, 125});
			}

			DrawLine(midpointX, 0, midpointX, height, WHITE);
			DrawLine(0, midpointY, width, midpointY, WHITE);

			DrawCircle( midpointX + point.x * grid_scale, midpointY - point.y * grid_scale, 5, RED);

		}
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
