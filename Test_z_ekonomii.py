import tkinter as tk
import random
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from pytania import questions  # Załaduj pytania z pliku 'pytania.py'

class QuizApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Test z Ekonomii")

        self.score = 0
        self.num_questions = len(questions) // 2
        self.selected_questions = random.sample(questions, self.num_questions)
        self.current_question_idx = 0

        # Setup GUI elements
        self.counter_label = tk.Label(root, text=f"Pytanie 1/{self.num_questions}", font=('Arial', 14))
        self.counter_label.pack(pady=10)

        self.question_label = tk.Label(root, text="", font=('Arial', 16), width=100, height=4)
        self.question_label.pack(pady=20)

        self.button_A = tk.Button(root, text="A", font=('Arial', 14), width=50, height=2,
                                  command=lambda: self.check_answer("A"))
        self.button_A.pack(fill='x')

        self.button_B = tk.Button(root, text="B", font=('Arial', 14), width=50, height=2,
                                  command=lambda: self.check_answer("B"))
        self.button_B.pack(fill='x')

        self.button_C = tk.Button(root, text="C", font=('Arial', 14), width=50, height=2,
                                  command=lambda: self.check_answer("C"))
        self.button_C.pack(fill='x')

        self.button_D = tk.Button(root, text="D", font=('Arial', 14), width=50, height=2,
                                  command=lambda: self.check_answer("D"))
        self.button_D.pack(fill='x')

        self.result_label = tk.Label(root, text="", font=('Arial', 14), width=50, height=2)
        self.result_label.pack(pady=20)

        # Frame for placing the chart
        self.chart_frame = tk.Frame(root)
        self.chart_frame.pack(pady=20)

        # Button to go to the next question
        self.next_button = tk.Button(root, text="Next", font=('Arial', 14), width=50, height=2, command=self.next_question)
        self.next_button.pack(pady=10)

        self.update_question()

    def update_question(self):
        """Update the question and options for the user."""
        if self.current_question_idx < self.num_questions:
            question_data = self.selected_questions[self.current_question_idx]
            self.question_label.config(text=question_data['question'])

            # Reset button colors to default (background)
            self.button_A.config(bg="SystemButtonFace")
            self.button_B.config(bg="SystemButtonFace")
            self.button_C.config(bg="SystemButtonFace")
            self.button_D.config(bg="SystemButtonFace")

            # Update the buttons with answer options
            answers = question_data['answers']
            self.button_A.config(text=answers[0])
            self.button_B.config(text=answers[1])
            self.button_C.config(text=answers[2])
            self.button_D.config(text=answers[3])

            self.result_label.config(text="", fg="black")  # Reset result label color to default
            self.counter_label.config(text=f"Pytanie {self.current_question_idx + 1}/{self.num_questions}")
        else:
            self.show_result()

    def check_answer(self, user_answer):
        """Check the user's answer and show feedback."""
        question_data = self.selected_questions[self.current_question_idx]
        correct_answer = question_data['correct']

        # Change result label color based on correctness
        if user_answer == correct_answer:
            self.score += 1
            self.result_label.config(text="Dobrze! To poprawna odpowiedź.\n", fg="green")
            self.highlight_button(user_answer, "green")  # Correct answer in green
        else:
            self.result_label.config(text=f"Źle! Poprawna odpowiedź to: {correct_answer}.\n", fg="red")
            self.highlight_button(user_answer, "red")  # Incorrect answer in red
            self.highlight_button(correct_answer, "green")  # Highlight correct answer in green

        # # Disable answer buttons after selection
        self.button_A.config(state="disabled")
        self.button_B.config(state="disabled")
        self.button_C.config(state="disabled")
        self.button_D.config(state="disabled")

    def next_question(self):
        """Move to the next question after the user clicks 'Next'."""
        # Enable answer buttons again for the next question
        self.button_A.config(state="normal")
        self.button_B.config(state="normal")
        self.button_C.config(state="normal")
        self.button_D.config(state="normal")

        self.current_question_idx += 1
        self.update_question()

    def highlight_button(self, answer, color):
        """Change the button background color to the specified color."""
        if answer == "A":
            self.button_A.config(bg=color)
        elif answer == "B":
            self.button_B.config(bg=color)
        elif answer == "C":
            self.button_C.config(bg=color)
        elif answer == "D":
            self.button_D.config(bg=color)

    def show_result(self):
        """Show the final result after the quiz is complete and display a pie chart in the GUI."""
        percentage = (self.score / self.num_questions) * 100
        self.question_label.config(text=f"Koniec quizu! Twój wynik: {self.score}/{self.num_questions}")
        self.result_label.config(text=f"Procent poprawnych odpowiedzi: {percentage:.2f}%", fg="black")

        # Show the pie chart in the GUI
        self.show_pie_chart(percentage)

    def show_pie_chart(self, percentage):
        """Display a pie chart with the percentage of correct answers in the GUI."""
        labels = ['Poprawne odpowiedzi', 'Błędne odpowiedzi']
        sizes = [percentage, 100 - percentage]
        colors = ['green', 'red']
        explode = (0.1, 0)  # 'explode' the first slice (correct answers)

        fig, ax = plt.subplots(figsize=(6, 6))
        ax.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%',
               shadow=True, startangle=140)
        ax.axis('equal')  # Equal aspect ratio ensures that pie chart is drawn as a circle.

        # Embed the pie chart in the GUI
        for widget in self.chart_frame.winfo_children():
            widget.destroy()  # Clear previous chart
        canvas = FigureCanvasTkAgg(fig, master=self.chart_frame)  # Create a canvas for the chart
        canvas.draw()
        canvas.get_tk_widget().pack()  # Pack the canvas into the frame

def run_quiz():
    root = tk.Tk()
    app = QuizApp(root)
    root.mainloop()

# Uruchom quiz
if __name__ == "__main__":
    run_quiz()
