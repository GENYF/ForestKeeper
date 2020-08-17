# 2019-ForestKeeper

1. 문제 인식

숲은 지구와 자연에 매우 중요한 존재이다. 생태계의 보고이며 많은 산소를 생산하고 있다. 하지만 20세기 이후 많은 숲이 파괴되고 있으며 그 원인은 주로 불법 벌목과 산불이다. 불법 벌목은 열대우림의 감소 요인으로 지금까지도 종종 주요국 정상회의 의제에 오르는 국제적인 문제이다. 주요 열대 목재 생산국에서 생산되는 목재의 30% ~ 70%, 전세계 목재의 5% ~ 10%가 불법 벌목이라 추산된다. 불법 벌목 문제는 매우 심각하며 해마다 세계적으로 1억 평방미터 이상의 목재가 불법적으로 벌목되었다. 불법 벌목은 해마다 증가하고 있으며 제대로 된 단속이 되지 못한 실정이다.
산불 또한 매우 심각하며 한국에서도 빈번히 발생하고 있다. 2019년 4월 4일 강원도 고성군에서는 산불이 발생하여 많은 숲을 불태웠다. 초기진압이 실패하여 순식간에 속초시 시내로 불이 옮겨붙었고, 동시다발적으로 강릉, 동해, 인제에서도 산불이 발생하였다. 국가재난 사태가 선포되었고 소방청에서는 최고 수준 3단계를 발령하여 전국의 모든 소방차를 출동 지시했다. 산불은 1755헥타르의 면적을 소실시켰고 3200억의 재산손실이 발생했으며 또한 2명이 사망하고 11명이 다치어 많은 인명 피해를 발생시켰다. 
이처럼 전 세계에선 다양한 원인으로 숲이 줄어들고 있으며 이 문제를 해결하기 위해 “Forest Keeper”를 기획하였다. 

2. 솔루션 상세 

“Forest Keeper”는 숲 지킴이라는 의미를 가지고 있다. 본 솔루션은 불법 벌목과 산불로부터 숲을 지키기 위해 기획했으며, 삼림 모니터링 장비와 서버, 클라이언트로 구성되어 있다. 삼림 모니터링 장비는 다양한 센서로 데이터를 실시간으로 측정하며 데이터를 분석하여 불법 벌목과 산불을 감시한다. 슬라이브 장비에서 불법 벌목 혹은 산불이 감지되면 통신 모듈을 통해  마스터 장비로 데이터를 전송하며 마스터 장비에서는 서버로 위치, 센서 데이터, 불법벌목 및 산불 정보를 전송하고 서버에서는 클라이언트에 측정 데이터를 제공한다. 클라이언트에서는 서버에서 전송받은 데이터와 실시간 위성 지도를 분석하여 관리자가 불법 벌목 및 산불을 확인하고 그에 따른 대응을 지시한다.

- 삼림 모니터링 장비
삼림 모니터링 장비는 능선 핵심 위치 및 불법 벌목 빛 산불 다발 발생 장소에 설치하며 데이터를 측정하는 슬레이브 장비와 데이터를 축적하고 서버에 전송하는 마스터 장비로 구성되어 있다. 슬레이브 장비는 불꽃 감지 센서, 온습도 센서, 연기 감지 센서, 소리 감지 센서, 진동 감지 센서, 라디오 통신 모듈로 구성되어 있고 실시간으로 센서 데이터를 측정하여 마스터 장비에 송신한다. 마스터 장비에서는 라디오 통신 모듈, 이더넷 통신 모듈, 임시 저장소로 구성되어 있으며 여러 대에 슬레이브 장비에서 데이터를 수신받아 데이터를 임시로 축적하고 이더넷을 통해 서버에 전송한다.

- 서버, 클라이언트
서버는 마스터 삼림 모니터링 장비에서 전송된 데이터를 축적하고 분석한다. 불꽃 감지 센서, 온습도 센서, 연기 감지 센서로 산불을 감지하고 소리 감지 센서 진동 감지 센서로 불법 벌목을 감지한다. 클라이언트는 지도를 기반으로 지도 위에 삼림 모니터링 장비의 위치가 표시되어 있고, 한눈에 센서 측정 데이터를 확인 할 수 있다. 만약 불법 벌목 혹은 산불이 발생하면 서버에서 센서 데이터를 분석하여 불법 벌목, 산불 의심 알림을 클라이언트에 전송하고 클라이언트에서는 의심 알림을 포커스 처리하여 관리자에게 표시한다. 관리자는 센서 데이터와 실시간 위성 지도를 바탕으로 분석하여 불법 벌목, 산불이 확실시 되었을 때 그에 따른 대응을 지시하고 이를 통해 초기 진압이 가능하다. 

  불법 벌목 모니터링 : 불법 벌목이 진행될 때 나오는 큰 소리와 진동을 감지하며 특정 데시벨 이상 소리와 진동이 발생하면 불법 벌목을 의심한다.

  산불 모니터링 : 산불이 발생했을 때 불꽃과 고온, 연기가 발생하는 것을 감지하며 불꽃과 고온, 연기를 감지하면 산불을 의심한다.
- 시제품 제작 방안
IoT 장비는 C/C++, Arduino IDE, Visual Studio 2017로 개발할 예정이다. 슬레이브 장비의 경우 경제성을 위해 최대한 작고 저렴하게 아두이노 나노를 사용하여 시제품을 개발할 예정이다. 마스터 장비의 경우 아두이노의 성능적 부족함을 해결하기 위해 ESP-32 보드를 사용하여 개발할 예정이다. 센서의 경우 정확성을 위해 다양한 센서를 테스트하여 사용할 것이며 라디오 통신은 APC-220 모듈을 사용하여 장거리 통신을 구현할 것이다. 전원 공급은 친환경을 위해 태양광 발전 패널을 이용할 예정이며 리튬 폴리머 배터리를 부착하여 밤과 흐린 날에도 정상적으로 작동이 가능하다.

3. 기대 효과

- 환경성
숲은 산소를 공급하고 공기를 정화하며 물을 저장한다. 또한 숲은 생태계의 보고이며 수많은 생물과 인간들이 숲에서 많은 도움을 받고 있다. 숲을 지키는 일은 곧 환경, 생물, 인간을 지키는 일이며 전 세계적으로 숲을 지키기 위해 큰 노력을 하고 있다. 본 솔루션을 통해 불법 벌목과 산불을 예방하고 차단할 수 있으며 숲을 지키는데 크게 기여를 할 수 있다.
 
- 경제성
“Forest Keeper”의 개발 비용은 약 5만 원으로 추정되며 숲마다 수십 개를 설치할 수 있을 정도의 매우 저렴한 가격이다. 현재 파괴되고 있는 숲의 면적을 고려한다면 이는 결코 높은 비용이 아니며 본 솔루션의 실행으로 얻게 될 경제 효과는 매우 크다. 숲을 지킴으로써 환경을 지킬 수 있으며 산불의 초기 진압이 수월해지기 때문에 산불로 인한 경적 손실을 최소화할 수 있어 잠재적으로 큰 경제성을 지니고 있다.
