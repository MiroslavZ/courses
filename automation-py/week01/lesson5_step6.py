from selenium import webdriver

browser = webdriver.Chrome()
browser.get("http://suninjuly.github.io/huge_form.html")
elements = browser.find_elements_by_tag_name("input")
for element in elements:
    element.send_keys("Мой ответ")

button = browser.find_element_by_css_selector("button.btn")
button.click()

alert = browser.switch_to.alert
print(alert.text.split()[-1])
alert.accept()

browser.close()
browser.quit()
