import pgzrun
import random
import math

#variáveis
WIDTH = 600
HEIGHT = 500
game_state = "MENU" #assume: MENU, GAME
music_sound = True
gravity = .5

#cores
color_white = (255, 255, 255)
color_black = (0, 0, 0)
color_gray = (150, 150, 150)
color_green = (0, 200, 0)
color_red = (200, 0, 0)
color_blue = (0, 0, 156)

#botões
button_play = Rect((WIDTH/2 - 100, HEIGHT/2 - 60), (200, 50))
button_sounds = Rect((WIDTH/2 - 100, HEIGHT/2 + 20), (200, 50))
button_quit = Rect((WIDTH/2 - 100, HEIGHT/2 + 100), (200, 50))

#classe do herói
class Hero:
    def __init__(self, x, y):
        self.x = x
        self.y = y

        self.vx = 0
        self.vy = 0

        self.width = 48
        self.height = 64

        self.jump_strength = -11
        self.max_speed = 3

        self.action = "idle"
        self.frame = 0
        self.timer = 0
        self.frame_speed = 0.05
        self.face_to_right = True #controle de direção
        self.rect = Rect((self.x, self.y), (self.width, self.height)) #área de colisão

        self.sprites = {
            "idle": ["hero_idle1", "hero_idle2"],
            "walk_right":  ["hero_walk1_r", "hero_walk2_r"],
            "jump_right": ["hero_jump_r"],
            "hit_right":  ["hero_hit_r"],
            "walk_left":  ["hero_walk1_l", "hero_walk2_l"],
            "jump_left": ["hero_jump_l"],
            "hit_left":  ["hero_hit_l"]
        }

    #verifica se está no chão
    def on_ground(self, platforms):
        for plat in platforms:
            if self.vy >= 0:  # só verifica quando está caindo
                if (self.y + self.height) >= plat.y and (self.y + self.height) <= plat.y + self.vy + 5:
                    if (self.x + self.width > plat.x) and (self.x < plat.x + 64):
                        self.y = plat.y - self.height
                        self.vy = 0
                        return True
        return False

    def draw(self):
        current_list = self.sprites[self.action]
        image_name = current_list[int(self.frame) % len(current_list)]
        screen.blit(image_name, (self.x, self.y))

    def update(self, platforms):
        #atualiza a posição do frame
        self.timer += self.frame_speed
        if self.timer >= 1:
            self.timer = 0
            self.frame += 1
        
        #movimentos do herói
        self.vx = 0
        keyboard_pressed = keyboard

        if keyboard_pressed.d or keyboard_pressed.right: #direita
            self.vx = self.max_speed
            self.action = "walk_right"
            self.face_to_right = True
        elif keyboard_pressed.a or keyboard_pressed.left: #esquerda
            self.vx = -self.max_speed
            self.action = "walk_left"
            self.face_to_right = False
        else: #parado
            if self.on_ground(platforms):
                self.action = "idle"

        if keyboard_pressed.space and self.on_ground(platforms): #pulo
            self.vy = self.jump_strength
            if self.face_to_right:
                self.action = "jump_right"
            else:
                self.action = "jump_left"

            if music_sound:
                sounds.jump.play()
        
        self.vy += gravity 
        self.x += self.vx
        self.y += self.vy
        
        self.on_ground(platforms)

#classe das plataformas
class Platform:
    def __init__(self, x, y, sprite_name):
        self.x = x
        self.y = y
        self.sprite = sprite_name 

    def draw(self):
        screen.blit(self.sprite, (self.x, self.y))
    

#desenha as plataformas
platforms = [
    Platform(0, 440, "terrain_dirt_block"),
    Platform(64, 440, "terrain_dirt_block"),
    Platform(128, 440, "terrain_dirt_block"),
    Platform(192, 440, "terrain_dirt_block"),
    Platform(256, 440, "terrain_dirt_block"),
]

hero = Hero(0, 300)
#função de desenhar na tela
def draw():
    screen.fill((0, 0, 0))
    if game_state == "MENU":
        #título
        screen.draw.text("Ataque da Natureza", center=(WIDTH/2, HEIGHT/2 - 120), fontsize=60, color=color_white)

        #botão de jogar
        screen.draw.filled_rect(button_play, color_green)
        
        #botão alternar música e sons
        screen.draw.filled_rect(button_sounds, color_blue)

        #botão de sair
        screen.draw.filled_rect(button_quit, color_red)

        screen.draw.text("Jogar", center=button_play.center, fontsize=30, color=color_white)
        if music_sound:
            screen.draw.text("Música (ON)", center=button_sounds.center, fontsize=30, color=color_white)
        else:
            screen.draw.text("Música (OFF)", center=button_sounds.center, fontsize=30, color=color_white)
        screen.draw.text("Sair", center=button_quit.center, fontsize=30, color=color_white)
    if game_state == "GAME":
        screen.clear()
        #desenha o fundo
        screen.blit("background", (0, 0))
        for block in platforms:
            block.draw()
        hero.draw()
        
        
#função de atualizar o jogo
def update():
    global game_state
    if game_state == "GAME" and keyboard.escape:
        game_state = "MENU"
    elif game_state == "GAME":
        hero.update(platforms)
    
#função de detecção do clique do mouse
def on_mouse_down(pos):
    global game_state, music_sound
    if game_state == "MENU":
        if button_play.collidepoint(pos):
            if music_sound:
                sounds.select_menu.play()
            print("Iniciando o jogo!")
            game_state = "GAME"
        elif button_sounds.collidepoint(pos):
            music_sound = not music_sound
            if music_sound:
                sounds.select_menu.play()
            if not music_sound:
                music.stop()
            else:
                music.play('music')
                music.set_volume(0.75)
            print("Alternando música e sons!")
        elif button_quit.collidepoint(pos):
            if music_sound:
                sounds.select_menu.play()
            print("Fechando o jogo!")
            exit()



music.play('music')
music.set_volume(0.9)

#função de rodar o jogo
pgzrun.go()