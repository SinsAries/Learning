from selenium import webdriver
from selenium.webdriver.edge.service import Service
import pandas as pd
import time

# Đường dẫn đầy đủ đến EdgeDriver
driver_path = "C:/Users/Admin/Desktop/NguyenTrongTatThanh/Learning/ACP Edu/edgedriver_win64/msedgedriver.exe"

# Khởi tạo service với EdgeDriver
service = Service(driver_path)
driver = webdriver.Edge(service=service)

# Hàm đăng nhập vào Codeforces
def login_to_codeforces(username, password):
    driver.get("https://codeforces.com/enter")
    time.sleep(2)

    # Nhập username và password
    driver.find_element(By.NAME, "handleOrEmail").send_keys(username)
    driver.find_element(By.NAME, "password").send_keys(password)
    driver.find_element(By.CLASS_NAME, "submit").click()
    time.sleep(3)  # Đợi đăng nhập

# Hàm lấy standings từ trang contest
def get_standings_from_contest(contest_url):
    driver.get(contest_url)
    time.sleep(3)  # Đợi trang load

    # Lấy tên các bài tập (thường nằm trên đầu bảng standings)
    problem_headers = driver.find_elements(By.CSS_SELECTOR, "table.standings thead th")
    problem_names = [header.text for header in problem_headers[3:]]  # Bỏ qua các cột đầu tiên (Rank, Handle, Total Points)
    
    standings_data = []
    rows = driver.find_elements(By.CSS_SELECTOR, "table.standings tr")[1:]  # Bỏ qua hàng tiêu đề
    
    for row in rows:
        cols = row.find_elements(By.TAG_NAME, "td")
        if len(cols) > 2:
            rank = cols[0].text
            handle = cols[1].text
            total_points = cols[2].text
            problem_points = [col.text for col in cols[3:]]  # Điểm cho từng bài
            
            # Gộp dữ liệu của thí sinh vào một hàng
            standings_data.append([rank, handle, total_points] + problem_points)
    
    # Tạo tiêu đề cột
    columns = ["Rank", "Handle", "Total Points"] + problem_names
    df = pd.DataFrame(standings_data, columns=columns)
    return df

# Lưu standings vào Excel
def save_to_excel(df, filename):
    df.to_excel(filename, index=False)
    print(f"Standings saved to {filename}")

# Đăng nhập vào Codeforces
username = "sinsaries"  # Thay bằng username của bạn
password = "286192070070291682UyenNhi"  # Thay bằng mật khẩu của bạn
login_to_codeforces(username, password)

# Lấy standings từ URL của contest trong group private
contest_url = "https://codeforces.com/group/oVr69pxzgo/contest/561894/standings"
df = get_standings_from_contest(contest_url)

# Lưu standings vào file Excel
if df is not None:
    save_to_excel(df, "private_group_standings_with_problem_points.xlsx")

# Đóng trình duyệt
driver.quit()
