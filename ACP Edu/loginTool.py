from selenium import webdriver
from selenium.webdriver.edge.service import Service
from selenium.webdriver.common.by import By
import pickle
import time

# Đường dẫn đến EdgeDriver
driver_path = "C:/Users/Admin/Desktop/NguyenTrongTatThanh/Learning/ACP Edu/edgedriver_win64/msedgedriver.exe"
service = Service(driver_path)
driver = webdriver.Edge(service=service)

# Hàm lưu cookie sau khi đăng nhập thành công
def save_cookies(driver, path):
    with open(path, "wb") as file:
        pickle.dump(driver.get_cookies(), file)

# Hàm tải cookie để sử dụng lại phiên đăng nhập
def load_cookies(driver, path):
    with open(path, "rb") as file:
        cookies = pickle.load(file)
        for cookie in cookies:
            driver.add_cookie(cookie)

# Bước 1: Đăng nhập thủ công
driver.get("https://codeforces.com/enter")
time.sleep(30)  # Đợi bạn đăng nhập và vượt qua các bước xác minh

# Bước 2: Lưu cookie sau khi đăng nhập thành công
save_cookies(driver, "codeforces_cookies.pkl")

# Sau khi lưu cookie, bạn có thể sử dụng cookie này để truy cập lại mà không cần đăng nhập
driver.quit()
