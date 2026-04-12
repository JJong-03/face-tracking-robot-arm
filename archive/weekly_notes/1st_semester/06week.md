# 📌 회의 기록

## 🗓 회의 정보

- **일시**: 2025년 4월 7일, 4월 9일, 4월10일 
- **장소**: 온, 오프라인  
- **참석자**: 김종원, 김동현, 손홍준, 최민주  
- **회의 주제**: 구입 재료 선정 및 구매



## 회의 내용
# 프로젝트 회의 기록 - 실시간 얼굴 추적 조명 & 카메라 제어 시스템

## 개요

- 실시간 얼굴 인식 기반으로 조명과 카메라의 위치를 자동으로 제어하는 스마트 시스템
- 음성 명령 기반 조명 밝기 조절 및 촬영 제어 기능 포함
- 로봇팔을 활용하여 X, Y축뿐만 아니라 입체적인 위치 조정이 가능함

---

## 시스템 구성 전략

### 1. 라즈베리파이 연결 방식
- **SSH 연결 사용 예정**
- AI 비전 기능 (YOLO, OpenCV 등)은 Raspberry Pi에서 처리

### 2. 데이터베이스
- **SQLite 사용**
  - 경량이며 별도 서버 설치 불필요
  - 복잡한 트랜잭션이 필요하지 않기 때문에 적합

---

## 부품 및 하드웨어 목록

### 김종원

- 음성 인식 모듈: **ReSpeaker Mic Array v2.0**
- Raspberry Pi 호환 가능

### 김동현

- **아두이노 UNO**
  - 보드: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1245596) (10,890원)
  - 전원: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1330492) (6,380원)
- **PCA9685 16채널 PWM 모듈**: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1382245) (16,500원)
- 점퍼 와이어: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1321195) (935원)
- **서보모터 전용 전원**
  - 18650 배터리 x3: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=14117576) (3,300원 × 3)
  - 배터리 홀더: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1278962) (1,089원)
- 로봇팔 프레임 (아크릴): [디바이스마트](https://www.devicemart.co.kr/goods/view?no=7919) (6,270원 × 3)

### 최민주

- **로지텍 C270 웹캠**
  - [쿠팡 링크](https://www.coupang.com/vp/products/1203604686)
  - [디바이스마트](https://www.devicemart.co.kr/goods/view?no=15424776)
- **서보 모터 MG996R**: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1313388) (보유 중 4개)
- **OpenCV 호환 확인 예정**
- **로봇팔 설계도 구상 필요**
- **리튬 이온 배터리 홀더**: [디바이스마트](https://www.devicemart.co.kr/goods/view?no=1278963)

---

## 음성 명령 처리 관련 부품

- Raspberry Pi: [Raspberry Pi 4 Model](https://www.devicemart.co.kr/goods/view?no=12234534) (85,910원)  
  [또는](https://www.devicemart.co.kr/goods/view?no=12553062) (123,970원)
- 마이크 모듈 (ReSpeaker Mic Array v2.0): [디바이스마트](https://www.devicemart.co.kr/goods/view?no=12169629) (81,180원)
- 조도센서 (조명 밝기 측정용):
  - [센서1](https://www.devicemart.co.kr/goods/view?no=1289977) (2,200원)
  - [센서2](https://www.devicemart.co.kr/goods/view?no=1383943) (3,630원)
  - [센서3](https://www.devicemart.co.kr/goods/view?no=12147969) (14,960원 - 해외)

---

## 밝기 조절 방식 비교

| 방식 | 설명 | 장점 | 단점 |
|------|------|------|------|
| AC 220V/110V TRIAC 모듈 | 가정용 전등 기반 | 고휘도, 실제 조명에 가까움 | 고전압 위험, 회로 복잡 |
| NeoPixel (WS2812/SK6812) | 소프트웨어 제어형 5V RGB 조명 | 제어 편리, 효과 다양 | 밝기 한계 (보완 가능: 은박지 등으로 반사효과 활용) |

- **최종 채택 예정 방식**: **NeoPixel 사용 예정**
  - 안전성과 구현 용이성 고려
  - 고휘도는 반사판 등을 이용해 보완

---

## 기타 비용 정리

- 가변 저항 밝기 조절 조명: 약 30,000원
- 카메라 모듈: 10,000원 이내
- 전체 예상 비용: **약 380,000원**

---

## 회의 요약

- 라즈베리파이는 SSH 기반으로 연결
- 데이터베이스는 SQLite 채택
- 조도 측정 → 조명 자동 밝기 조절에 활용
- 고전압 TRIAC 방식은 위험성 때문에 배제
- 로봇팔 설계는 지속적으로 보완 예정
- 각 구성 요소는 Raspberry Pi + Arduino 조합으로 병렬 처리 예정

