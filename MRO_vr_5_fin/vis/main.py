import os
import matplotlib.pyplot as plt

def read_coordinates(file_path):
    coordinates = []
    with open(file_path, 'r') as file:
        for line in file:
            x, y = map(float, line.strip().split())
            coordinates.append((x, y))
    return coordinates

def read_lines_coordinates(file_path):
    lines = []
    with open(file_path, 'r') as file:
        for line in file:
            x1, x2, y = map(float, line.strip().split())
            lines.append((x1, x2, y))  # Сохраняем как кортежи
    return lines

def plot_coordinates(all_coordinates):
    for i, coordinates in enumerate(all_coordinates):
        x_values, y_values = zip(*coordinates)
        plt.scatter(x_values, y_values, label=f'Класс {i + 1}')  # Используем scatter для точек

def plot_lines(lines):
    for line in lines:
        x1, x2, y = line
        x1 = abs(y/x1)
        x2 = abs(y/x2)
        plt.plot([x1, 0], [0, x2], color='r', linewidth=2, label='Линия' if line == lines[0] else "")  # Добавляем метку только для первой линии

if __name__ == "__main__":
    all_coordinates = []
    directory_path = 'C:/MRO_vr_5_fin/MRO_vr_5_fin'  # Укажите путь к директории с файлами

    # Получаем список всех файлов в директории для точек
    for filename in os.listdir(directory_path):
        if filename.startswith('points_set') and filename.endswith('.txt'):
            file_path = os.path.join(directory_path, filename)
            coordinates = read_coordinates(file_path)
            all_coordinates.append(coordinates)

    # Чтение линий из другого файла
    lines_file_path = 'C:/MRO_vr_5_fin/output_ho_vector.txt'  # Укажите путь к файлу с линиями
    lines = read_lines_coordinates(lines_file_path)

    # Визуализация точек
    plot_coordinates(all_coordinates)

    # Визуализация линий
    plot_lines(lines)

    # Настройка графика
    plt.title('Визуализация точек и линий на плоскости')
    plt.xlabel('X координаты')
    plt.ylabel('Y координаты')
    plt.grid()
    plt.axhline(0, color='black', linewidth=0.5, ls='--')
    plt.axvline(0, color='black', linewidth=0.5, ls='--')
    plt.legend()

    # Показать график
    plt.show()