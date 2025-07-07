#include "raylib.h"
#include "raymath.h"

#include <stdio.h>

int main(void) {
	int width = 320;
	int height = 240;
	int scale = 4;
	int widthp = width * scale;
	int heightp = height * scale;

	static RenderTexture2D surf = {0};
	static Shader shader = {0};
	static Texture2D tex = {0};

	int x = 0;
	int y = 0;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(widthp, heightp, "Scaled");

	surf = LoadRenderTexture(width, height);
	shader = LoadShader(0, "shader.fs");

	tex = LoadTexture("Rosa_spinosissima(Gavarrera).jpg");

/*
	int scaleLoc = GetShaderLocation(shader, "scale");
	int scalefLoc = GetShaderLocation(shader, "scalef");
	float scalef = (float)scale;
	SetShaderValue(shader, scaleLoc, &scale, SHADER_UNIFORM_INT);
	SetShaderValue(shader, scalefLoc, &scalef, SHADER_UNIFORM_FLOAT);
	*/

	int widthpfLoc = GetShaderLocation(shader, "widthpf");
	int heightpfLoc = GetShaderLocation(shader, "heightpf");
	float widthpf = (float)widthp;
	float heightpf = (float)heightp;
	SetShaderValue(shader, widthpfLoc, &widthpf, SHADER_UNIFORM_FLOAT);
	SetShaderValue(shader, heightpfLoc, &heightpf, SHADER_UNIFORM_FLOAT);
	int fullscreen=false;

	while (!WindowShouldClose()) {
		if (!fullscreen){
			x = (GetScreenWidth() - widthp) / 2;
			y = (GetScreenHeight() - heightp) / 2;
		}
		else{
			x = (GetMonitorWidth(GetCurrentMonitor())- widthp) / 2;
			y = (GetMonitorHeight(GetCurrentMonitor()) - heightp) / 2;
		}

		if (IsKeyPressed(KEY_F)) {
			ToggleBorderlessWindowed();
			fullscreen = !fullscreen;
		}
/*
		BeginTextureMode(surf);
		 DrawTexturePro(tex, (Rectangle){0, 0, tex.width, tex.height}, (Rectangle){0, 0, width, height}, (Vector2){0, 0}, 0.0f, WHITE);
		EndTextureMode();
*/
		BeginDrawing();
		 ClearBackground(BLACK);
		 BeginShaderMode(shader);
/*
		  DrawTexturePro(surf.texture, (Rectangle){0, 0, surf.texture.width, surf.texture.height}, (Rectangle){x, y, widthp, heightp}, (Vector2){0, 0}, 0.0f, WHITE);
*/
		  DrawTexturePro(tex, (Rectangle){0, 0, tex.width, tex.height}, (Rectangle){x, y, widthp, heightp}, (Vector2){0, 0}, 0.0f, WHITE);
		 EndShaderMode();
		EndDrawing();
	}
	UnloadTexture(tex);
	UnloadShader(shader);
	UnloadRenderTexture(surf);
	CloseWindow();
	return 0;
}
