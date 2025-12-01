// @ts-nocheck
/* eslint-disable */
/* 
  이 파일은 Unframer(Framer → 코드 변환)로 생성된 React 컴포넌트입니다.
  - 자동 생성 파일이므로 구조를 바꾸지 말고 주석만 추가했습니다.
  - 주요 목적: Framer에서 설계된 페이지(또는 섹션)를 React 컴포넌트로 렌더링.
  - SmartComponentScopedContainer로 외부 위젯(Slideshow/GoogleMaps/Calcom 등)을 안전하게 포함합니다.
*/
"use client";

/**
 * 타입 정의(문서용)
 * - Locale: 로케일 식별자 타입 (string)
 * - Props: 컴포넌트가 받을 수 있는 주요 prop들
 */
/**
 * @typedef Locale
 * string
 */
/**
 * @typedef {{
 * children?: React.ReactNode
 * locale?: Locale
 * style?: React.CSSProperties
 * className?: string
 * id?: string
 * ref?: any
 * width?: any
 * height?: any
 * layoutId?: string
}} Props
*/

// 외부(번들된) 스마트 컴포넌트 임포트: Slideshow, GoogleMaps, Calcom, 네비(또는 상단) 컴포넌트 등
import { Calcom } from "./chunks/chunk-N54VTD32.js";
import { GoogleMaps } from "./chunks/chunk-WJ4M4KHJ.js";
import { Slideshow } from "./chunks/chunk-FET5STFD.js";
import { stdin_default } from "./chunks/chunk-U6ARRNOW.js";
import { routes } from "./chunks/chunk-RX5K52XN.js";

// virtual 엔트리 표시 (Unframer의 메타)
import { Fragment as Fragment2 } from "react";
import { ContextProviders } from "unframer";

// React JSX 런타임 (빌드된 형태에서 _jsx / _jsxs 사용)
import { jsx as _jsx, jsxs as _jsxs } from "react/jsx-runtime";

/*
  unframer 유틸 및 컴포넌트
  - addFonts: 컴포넌트 전용 폰트 등록
  - ComponentViewportProvider: 스마트 컴포넌트에 뷰포트 정보 주입
  - cx: 클래스명 결합 유틸
  - getFonts: 서브컴포넌트의 폰트 메타 수집
  - Image, RichText: Framer가 사용하는 추상화된 UI 요소
  - SmartComponentScopedContainer: 외부 모듈을 스코프하여 삽입
  - useComponentViewport / useLocaleInfo / useVariantState: 런타임 훅
  - withCSS: 컴포넌트 전용 CSS 적용 HOC
*/
import {
	addFonts,
	ComponentViewportProvider,
	cx,
	getFonts,
	Image,
	RichText,
	SmartComponentScopedContainer,
	useComponentViewport,
	useLocaleInfo,
	useVariantState,
	withCSS,
} from "unframer";
import { LayoutGroup, motion, MotionConfigContext } from "unframer";
import * as React from "react";
import { useRef } from "react";

/* --- 폰트 메타 수집: 서브컴포넌트가 필요로 하는 폰트 정보를 병합하기 위해 사용 --- */
var Navigation3Fonts = getFonts(stdin_default);
var SlideshowFonts = getFonts(Slideshow);
var GoogleMapsFonts = getFonts(GoogleMaps);
var CalComFonts = getFonts(Calcom);

/* --- CSS 스코프용 해시: 컴포넌트 스타일을 격리하기 위한 고유 식별자 --- */
var serializationHash = "framer-Ret0S";

/* variant 식별자 → 클래스명 맵 (Framer 변형 관리) */
var variantClassNames = {
	TUKB6rSNU: "framer-v-1v99hk0",
};

/* 공통 transition 설정: Transition 컴포넌트에서 사용 */
var transition1 = {
	bounce: 0.2,
	delay: 0,
	duration: 0.4,
	type: "spring",
};

/* transformTemplate: transform 문자열을 일관되게 생성 (translateX 보정 포함) */
var transformTemplate1 = (_, t) => `translateX(-50%) ${t}`;

/* 
  Transition 컴포넌트:
  - MotionConfigContext의 기본 config를 상속받아 value로 전달된 transition을 병합해서 Provider로 재공급.
  - 내부의 motion 요소들이 동일한 transition 설정을 공유하도록 함.
*/
var Transition = ({ value, children }) => {
	const config = React.useContext(MotionConfigContext);
	const transition = value ?? config.transition;
	const contextValue = React.useMemo(
		() => ({
			...config,
			transition,
		}),
		[JSON.stringify(transition)],
	);
	return (
		<MotionConfigContext.Provider value={contextValue}>
			{children}
		</MotionConfigContext.Provider>
	);
};

/* Variants: framer-motion의 variants 처리를 위한 래퍼(Fragment 기반) */
var Variants = motion.create(React.Fragment);

/* getProps: 런타임에 전달된 불필요한 프레임 속성(height, id, width)을 제거 */
var getProps = ({ height, id, width, ...props }) => {
	return {
		...props,
	};
};

/* layoutDependency 생성 유틸:
   - props.layoutDependency가 있으면 variants 값을 접두로 붙여 반환
   - 레이아웃 변경 의존성 키 일관성 확보 목적
*/
var createLayoutDependency = (props, variants) => {
	if (props.layoutDependency)
		return variants.join("-") + props.layoutDependency;
	return variants.join("-");
};

/* -------------------------------
   메인 컴포넌트 정의 (forwardRef 사용)
   - Framer에서 디자인된 트리를 그대로 반환합니다.
   - SmartComponentScopedContainer를 통해 외부 모듈을 스코프하여 삽입합니다.
--------------------------------*/
var Component = /* @__PURE__ */ React.forwardRef(function (props, ref) {
	// 전달된 ref가 없을 경우 내부 fallbackRef 사용
	const fallbackRef = useRef(null);
	const refBinding = ref ?? fallbackRef;

	// 레이아웃 그룹에 사용할 기본 layoutId (React.useId)
	const defaultLayoutId = React.useId();

	// 로케일 정보 및 변경 함수 (unframer 훅)
	const { activeLocale, setLocale } = useLocaleInfo();

	// 컴포넌트 뷰포트 정보 (스크롤 위치/폭 등)
	const componentViewport = useComponentViewport();

	// 전달된 props에서 style, className, layoutId, variant 제외
	const { style, className, layoutId, variant, ...restProps } = getProps(props);

	/*
	  useVariantState: Framer에서 생성된 variant(상태) 관리를 위해 사용
	  반환값 예: baseVariant, classNames, gestureHandlers, variants 등
	*/
	const {
		baseVariant,
		classNames,
		clearLoadingGesture,
		gestureHandlers,
		gestureVariant,
		isLoading,
		setGestureState,
		setVariant,
		variants,
	} = useVariantState({
		defaultVariant: "TUKB6rSNU",
		ref: refBinding,
		variant,
		variantClassNames,
	});

	// layoutDependency 문자열 생성 (애니메이션/레이아웃 동기화용)
	const layoutDependency = createLayoutDependency(props, variants);

	// 공유 스타일 클래스명(필요 시 확장)
	const sharedStyleClassNames = [];

	// 컴포넌트 스코프용 클래스 결합
	const scopingClassNames = cx(serializationHash, ...sharedStyleClassNames);

	/* JSX 트리 반환
	   구조 요약:
	   LayoutGroup
	     └─ Variants
	        └─ Transition
	           └─ motion.div (루트)
	              ├─ ComponentViewportProvider / SmartComponentScopedContainer (상단/내비 등)
	              └─ motion.div ("Features": 실제 콘텐츠)
	*/
	return (
		<LayoutGroup id={layoutId ?? defaultLayoutId}>
			{/* Variants: Framer variant 애니메이션을 관리 */}
			<Variants animate={variants} initial={false}>
				{/* Transition: 공통 transition 적용 */}
				<Transition value={transition1}>
					<motion.div
						{...restProps}
						{...gestureHandlers} // 제스처(드래그/터치) 핸들러 병합
						className={cx(
							scopingClassNames,
							"framer-1v99hk0",
							className,
							classNames,
						)}
						data-framer-name={"Variant 1"}
						layoutDependency={layoutDependency}
						layoutId={"TUKB6rSNU"}
						ref={refBinding}
						style={{
							...style,
						}}
					>
						{/* 
						  상단/네비게이션을 위한 뷰포트 정보 제공자
						  SmartComponentScopedContainer는 외부 모듈(헤더 등)을 안전하게 렌더링합니다.
						*/}
						<ComponentViewportProvider
							height={64}
							width={componentViewport?.width || "100vw"}
							y={(componentViewport?.y || 0) + 0}
						>
							<SmartComponentScopedContainer
								className={"framer-zra8u6-container"}
								layoutDependency={layoutDependency}
								layoutId={"pNkecB3Hl-container"}
								nodeId={"pNkecB3Hl"}
								rendersWithMotion={true}
								scopeId={"rARdbBz3O"}
								transformTemplate={transformTemplate1}
							>
								{_jsx(stdin_default, {
									height: "100%",
									id: "pNkecB3Hl",
									layoutId: "pNkecB3Hl",
									style: {
										width: "100%",
									},
									width: "100%",
								})}
							</SmartComponentScopedContainer>
						</ComponentViewportProvider>

						{/* 주요 콘텐츠 영역: "Features" 섹션 (흰 배경) */}
						<motion.div
							className={"framer-ulorh8"}
							data-framer-name={"Features"}
							layoutDependency={layoutDependency}
							layoutId={"zOCSQOXt0"}
							style={{
								backgroundColor: "rgb(255, 255, 255)",
							}}
							transformTemplate={transformTemplate1}
						>
							{/* 중앙 가로 컨테이너(첫 번째 행: 설명 + 이미지/슬라이드) */}
							<motion.div
								className={"framer-csmpa3"}
								layoutDependency={layoutDependency}
								layoutId={"kjLxMd4no"}
							>
								{/* 왼쪽 텍스트 블록: 제목 + 설명 */}
								<motion.div
									className={"framer-1dphzao"}
									layoutDependency={layoutDependency}
									layoutId={"x2vQeI69s"}
								>
									{/* 제목(대문자/관계된 스타일 속성들) */}
									<RichText
										__fromCanvasComponent={true}
										className={"framer-vormvr"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"wsQ39kVUf"}
										style={{
											"--extracted-2gg91v": '"opsz" 32, "wght" 700',
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											{/* 제목 텍스트 (유니코드 이스케이프로 한국어 표기) */}
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOekF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv01' on, 'cv09' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "32px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 700)',
													"--framer-letter-spacing": "-0.03em",
													"--framer-line-height": "1em",
													"--framer-text-alignment": "left",
												}}
											>
												{"\uAC00\uB85C\uC218\uAE38"}
											</motion.p>
										</React.Fragment>
									</RichText>

									{/* 본문 설명(여러 문단 포함 가능) */}
									<RichText
										__fromCanvasComponent={true}
										className={"framer-1hn1lh8"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"wa_2ynPnt"}
										style={{
											"--extracted-2gg91v": '"opsz" 32, "wght" 500',
											"--extracted-r6o4lv": "rgb(153, 153, 153)",
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											{/* 설명 텍스트: 장소/역사/특징 등을 설명하는 문단 */}
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOVEF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv09' on, 'cv01' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "22px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 500)',
													"--framer-letter-spacing": "-0.01em",
													"--framer-text-alignment": "left",
													"--framer-text-color":
														"var(--extracted-r6o4lv, rgb(153, 153, 153))",
												}}
											>
												{
													"\uD55C\uAD6D\uC758 \uC544\uB984\uB2E4\uC6B4 \uAE38 100\uC120\uC5D0 \uC120\uC815\uB418\uC5B4 \uC804\uAD6D\uC5D0\uC11C \uAC00\uC7A5 \uC544\uB984\uB2E4\uC6B4 \uAE38\uB85C \uBF51\uD788\uB294 \uCCAD\uC8FC\uAC00\uB85C\uC218\uAE38\uC740 \uACBD\uBD80\uACE0\uC18D\uB3C4\uB85C \uCCAD\uC8FC \uC778\uD130 \uCCB4\uC778\uC9C0\uC5D0\uC11C \uAC00\uACBD\uCC9C \uC8FD\uCC9C\uAD50\uC5D0 \uAC78\uCCD0 1948\uB144\uC5D0 \uC2DD\uC7AC\uB41C 1,527\uADF8\uB8E8\uC758 \uD50C\uB77C\uD0C0\uB108\uC2A4\uAC00 \uB9C8\uCE58 \uD130\uB110\uC744 \uC774\uB8E8\uB4EF \uC7A5\uAD00\uC744 \uC5F0\uCD9C\uD558\uACE0 \uC788\uC5B4 \uC804\uAD6D\uC758 \uC9C4\uC785\uB85C \uC911 \uAC00\uC7A5 \uC544\uB984\uB2F5\uACE0 \uC6B4\uCE58 \uC788\uB2E4. \uC601\uD654 \uB9CC\uCD94\uC640 \uB4DC\uB77C\uB9C8 \uBAA8\uB798\uC2DC\uACC4\uC758 \uCD2C\uC601\uC7A5\uC18C\uB85C\uB3C4 \uC720\uBA85\uD55C \uC774\uACF3\uC740 \uC5F0\uB463\uBE5B \uBD04\uACFC \uC2F1\uADF8\uB7EC\uC6B4 \uB179\uC74C, \uAC00\uC744\uBE5B \uAC70\uB9AC, \uBE44\uC6C0\uC758 \uC790\uC138\uB97C \uBCF4\uC5EC\uC8FC\uB294 \uACA8\uC6B8\uAE4C\uC9C0 \uCD98\uD558\uCD94\uB3D9 \uC0AC\uACC4\uC808 \uB9C8\uB2E4 \uD2B9\uC0C9 \uC788\uB294 \uBAA8\uC2B5\uC73C\uB85C \uCCAD\uC8FC\uB97C \uCC3E\uB294 \uC774\uB4E4\uC758 \uAC10\uD0C4\uC744 \uC790\uC544\uB0B4\uACE0 \uC788\uB2E4. \uAC00\uC871\uACFC \uC5F0\uC778\uACFC \uD568\uAED8 \uB4DC\uB77C\uC774\uBE0C \uD558\uAE30\uC5D0\uB3C4 \uC88B\uC740 \uCCAD\uC8FC\uC758 \uC228\uACA8\uC9C4 \uBA85\uC18C\uC774\uB2E4."
												}
											</motion.p>
										</React.Fragment>
									</RichText>
								</motion.div>

								{/* 오른쪽: 이미지/슬라이드 쇼 영역 */}
								<motion.div
									className={"framer-1vleu1q"}
									data-framer-name={"Placeholder"}
									layoutDependency={layoutDependency}
									layoutId={"ZSWcb8GPp"}
									style={{
										backgroundColor: "rgb(245, 245, 245)",
										borderBottomLeftRadius: 20,
										borderBottomRightRadius: 20,
										borderTopLeftRadius: 20,
										borderTopRightRadius: 20,
									}}
								>
									<ComponentViewportProvider>
										<SmartComponentScopedContainer
											className={"framer-1ru02d7-container"}
											isAuthoredByUser={true}
											isModuleExternal={true}
											layoutDependency={layoutDependency}
											layoutId={"eUGSix5K2-container"}
											nodeId={"eUGSix5K2"}
											rendersWithMotion={true}
											scopeId={"rARdbBz3O"}
										>
											{/* Slideshow: 이미지 슬롯 배열로 구성된 외부 모듈 */}
											<Slideshow
												alignment={"center"}
												arrowOptions={{
													arrowFill: "rgba(0, 0, 0, 0.2)",
													arrowGap: 10,
													arrowPadding: 20,
													arrowPaddingBottom: 0,
													arrowPaddingLeft: 0,
													arrowPaddingRight: 0,
													arrowPaddingTop: 0,
													arrowPosition: "auto",
													arrowRadius: 40,
													arrowShouldFadeIn: false,
													arrowShouldSpace: true,
													arrowSize: 40,
													showMouseControls: true,
												}}
												autoPlayControl={true}
												borderRadius={0}
												direction={"left"}
												dragControl={false}
												effectsOptions={{
													effectsHover: true,
													effectsOpacity: 1,
													effectsPerspective: 1200,
													effectsRotate: 0,
													effectsScale: 1,
													playOffscreen: false,
												}}
												fadeOptions={{
													fadeAlpha: 0,
													fadeContent: false,
													fadeInset: 0,
													fadeWidth: 25,
													overflow: false,
												}}
												gap={10}
												height={"100%"}
												id={"eUGSix5K2"}
												intervalControl={2.5}
												itemAmount={1}
												layoutId={"eUGSix5K2"}
												padding={0}
												paddingBottom={0}
												paddingLeft={0}
												paddingPerSide={false}
												paddingRight={0}
												paddingTop={0}
												progressOptions={{
													dotsActiveOpacity: 1,
													dotsBackground: "rgba(0, 0, 0, 0.2)",
													dotsBlur: 0,
													dotsFill: "rgb(255, 255, 255)",
													dotsGap: 10,
													dotsInset: 10,
													dotSize: 10,
													dotsOpacity: 0.5,
													dotsPadding: 10,
													dotsRadius: 50,
													showProgressDots: true,
												}}
												slots={[
													/* 각 슬롯은 Image 컴포넌트를 통해 이미지 메타를 전달 */
													<Image
														background={{
															alt: "",
															fit: "fill",
															intrinsicHeight: 959.9999713897713,
															intrinsicWidth: 959.9999713897713,
															pixelHeight: 1280,
															pixelWidth: 1280,
															sizes: "960px",
															src: "https://framerusercontent.com/images/S4RWqmyemcOankcCAVeHrtAoQ.jpeg?width=1280&height=1280",
															srcSet:
																"https://framerusercontent.com/images/S4RWqmyemcOankcCAVeHrtAoQ.jpeg?scale-down-to=512&width=1280&height=1280 512w,https://framerusercontent.com/images/S4RWqmyemcOankcCAVeHrtAoQ.jpeg?scale-down-to=1024&width=1280&height=1280 1024w,https://framerusercontent.com/images/S4RWqmyemcOankcCAVeHrtAoQ.jpeg?width=1280&height=1280 1280w",
														}}
														className={"framer-2lqcok"}
														data-framer-name={"\xCA\xB0\x80\xEB\xA1\x9C1"}
														layoutDependency={layoutDependency}
														layoutId={"a63q_07C7"}
													/>,
													<Image
														background={{
															alt: "",
															fit: "fill",
															intrinsicHeight: 450.7499865666036,
															intrinsicWidth: 674.999979883433,
															pixelHeight: 601,
															pixelWidth: 900,
															sizes: "675px",
															src: "https://framerusercontent.com/images/MLLugjWFaVMxHzHe2AH8rLE70.jpeg?width=900&height=601",
															srcSet:
																"https://framerusercontent.com/images/MLLugjWFaVMxHzHe2AH8rLE70.jpeg?scale-down-to=512&width=900&height=601 512w,https://framerusercontent.com/images/MLLugjWFaVMxHzHe2AH8rLE70.jpeg?width=900&height=601 900w",
														}}
														className={"framer-uafayz"}
														data-framer-name={"\xCA\xB0\x80\xEB\xA1\x9C2"}
														layoutDependency={layoutDependency}
														layoutId={"jIaMHSBCl"}
													/>,
													<Image
														background={{
															alt: "",
															fit: "fill",
															intrinsicHeight: 959.9999713897713,
															intrinsicWidth: 959.9999713897713,
															pixelHeight: 1280,
															pixelWidth: 1280,
															sizes: "960px",
															src: "https://framerusercontent.com/images/yioufdSSTbeGJHeIhL7TULBOk.jpeg?width=1280&height=1280",
															srcSet:
																"https://framerusercontent.com/images/yioufdSSTbeGJHeIhL7TULBOk.jpeg?scale-down-to=512&width=1280&height=1280 512w,https://framerusercontent.com/images/yioufdSSTbeGJHeIhL7TULBOk.jpeg?scale-down-to=1024&width=1280&height=1280 1024w,https://framerusercontent.com/images/yioufdSSTbeGJHeIhL7TULBOk.jpeg?width=1280&height=1280 1280w",
														}}
														className={"framer-teaxw2"}
														data-framer-name={"\xCA\xB0\x80\xEB\xA1\x9C3"}
														layoutDependency={layoutDependency}
														layoutId={"nIWHJkXmS"}
													/>,
													<Image
														background={{
															alt: "",
															fit: "fill",
															intrinsicHeight: 959.9999713897713,
															intrinsicWidth: 959.9999713897713,
															pixelHeight: 1280,
															pixelWidth: 1280,
															sizes: "960px",
															src: "https://framerusercontent.com/images/8G36YlKUrynpQoiHmwXhNB9yLA.jpeg?width=1280&height=1280",
															srcSet:
																"https://framerusercontent.com/images/8G36YlKUrynpQoiHmwXhNB9yLA.jpeg?scale-down-to=512&width=1280&height=1280 512w,https://framerusercontent.com/images/8G36YlKUrynpQoiHmwXhNB9yLA.jpeg?scale-down-to=1024&width=1280&height=1280 1024w,https://framerusercontent.com/images/8G36YlKUrynpQoiHmwXhNB9yLA.jpeg?width=1280&height=1280 1280w",
														}}
														className={"framer-n22j9s"}
														data-framer-name={"\xCA\xB0\x80\xEB\xA1\x9C4"}
														layoutDependency={layoutDependency}
														layoutId={"dQH2eMlZ3"}
													/>,
													<Image
														background={{
															alt: "",
															fit: "fill",
															intrinsicHeight: 719.9999785423286,
															intrinsicWidth: 959.9999713897713,
															pixelHeight: 960,
															pixelWidth: 1280,
															sizes: "960px",
															src: "https://framerusercontent.com/images/qfXF6nKWRFl8jssuPze088w33CU.jpeg?width=1280&height=960",
															srcSet:
																"https://framerusercontent.com/images/qfXF6nKWRFl8jssuPze088w33CU.jpeg?scale-down-to=512&width=1280&height=960 512w,https://framerusercontent.com/images/qfXF6nKWRFl8jssuPze088w33CU.jpeg?scale-down-to=1024&width=1280&height=960 1024w,https://framerusercontent.com/images/qfXF6nKWRFl8jssuPze088w33CU.jpeg?width=1280&height=960 1280w",
														}}
														className={"framer-fqb4qd"}
														data-framer-name={"\xCA\xB0\x80\xEB\xA1\x9C5"}
														layoutDependency={layoutDependency}
														layoutId={"jBEoRum75"}
													/>,
												]}
												startFrom={0}
												style={{
													height: "100%",
													width: "100%",
												}}
												transitionControl={{
													damping: 40,
													delay: 0,
													mass: 1,
													stiffness: 200,
													type: "spring",
												}}
												width={"100%"}
											/>
										</SmartComponentScopedContainer>
									</ComponentViewportProvider>
								</motion.div>
							</motion.div>

							{/* 두 번째 행: 지도(좌) + 기본 정보(우) */}
							<motion.div
								className={"framer-1z6ty7"}
								layoutDependency={layoutDependency}
								layoutId={"h3G6x5ovw"}
							>
								{/* 좌측: GoogleMaps(스마트 컨테이너 내 삽입) */}
								<motion.div
									className={"framer-qc1dan"}
									data-framer-name={"Placeholder"}
									layoutDependency={layoutDependency}
									layoutId={"kbGv_ZeRS"}
									style={{
										backgroundColor: "rgb(245, 245, 245)",
										borderBottomLeftRadius: 20,
										borderBottomRightRadius: 20,
										borderTopLeftRadius: 20,
										borderTopRightRadius: 20,
									}}
								>
									<ComponentViewportProvider>
										<SmartComponentScopedContainer
											className={"framer-16wjdxo-container"}
											isAuthoredByUser={true}
											isModuleExternal={true}
											layoutDependency={layoutDependency}
											layoutId={"gPTHtD1J_-container"}
											nodeId={"gPTHtD1J_"}
											rendersWithMotion={true}
											scopeId={"rARdbBz3O"}
										>
											<GoogleMaps
												borderRadius={0}
												bottomLeftRadius={0}
												bottomRightRadius={0}
												coordinates={"\uCCAD\uC8FC \uAC00\uB85C\uC218\uAE38"}
												height={"100%"}
												id={"gPTHtD1J_"}
												isMixedBorderRadius={false}
												layoutId={"gPTHtD1J_"}
												style={{
													height: "100%",
													width: "100%",
												}}
												topLeftRadius={0}
												topRightRadius={0}
												width={"100%"}
												zoom={15}
											/>
										</SmartComponentScopedContainer>
									</ComponentViewportProvider>
								</motion.div>

								{/* 우측: 기본 정보(주소, 영업시간, 전화번호 등) */}
								<motion.div
									className={"framer-2frul8"}
									layoutDependency={layoutDependency}
									layoutId={"pccS3qz2T"}
								>
									<RichText
										__fromCanvasComponent={true}
										className={"framer-qbr9eh"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"p35FXBbZu"}
										style={{
											"--extracted-2gg91v": '"opsz" 32, "wght" 700',
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOekF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv01' on, 'cv09' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "32px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 700)',
													"--framer-letter-spacing": "-0.03em",
													"--framer-line-height": "1em",
													"--framer-text-alignment": "left",
												}}
											>
												{"\uAE30\uBCF8 \uC815\uBCF4"}
											</motion.p>
										</React.Fragment>
									</RichText>

									{/* 상세 정보 텍스트 블록 */}
									<RichText
										__fromCanvasComponent={true}
										className={"framer-mt3197"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"J95ZF9aeI"}
										style={{
											"--extracted-1iakedh": "rgb(153, 153, 153)",
											"--extracted-1qhja7k": '"opsz" 32, "wght" 500',
											"--extracted-2gg91v": '"opsz" 32, "wght" 500',
											"--extracted-2gxw0f": "rgb(153, 153, 153)",
											"--extracted-l7dsdt": '"opsz" 32, "wght" 500',
											"--extracted-r6o4lv": "rgb(153, 153, 153)",
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											{/* 주소, 영업시간, 전화번호 등 */}
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOVEF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv09' on, 'cv01' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "22px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 500)',
													"--framer-letter-spacing": "-0.01em",
													"--framer-text-alignment": "left",
													"--framer-text-color":
														"var(--extracted-r6o4lv, rgb(153, 153, 153))",
												}}
											>
												{
													"\uC8FC\uC18C : \uCDA9\uBD81 \uCCAD\uC8FC\uC2DC \uD765\uB355\uAD6C \uD734\uC554\uB3D9 353-2"
												}
											</motion.p>
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOVEF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv09' on, 'cv01' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "22px",
													"--framer-font-variation-axes":
														'var(--extracted-1qhja7k, "opsz" 32, "wght" 500)',
													"--framer-letter-spacing": "-0.01em",
													"--framer-text-alignment": "left",
													"--framer-text-color":
														"var(--extracted-2gxw0f, rgb(153, 153, 153))",
												}}
											>
												{"\uC601\uC5C5 \uC2DC\uAC04 : 24\uC2DC \uAC04"}
											</motion.p>
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOVEF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv09' on, 'cv01' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "22px",
													"--framer-font-variation-axes":
														'var(--extracted-l7dsdt, "opsz" 32, "wght" 500)',
													"--framer-letter-spacing": "-0.01em",
													"--framer-text-alignment": "left",
													"--framer-text-color":
														"var(--extracted-1iakedh, rgb(153, 153, 153))",
												}}
											>
												{"\uC804\uD654\uBC88\uD638 : 043-201-2753"}
											</motion.p>
										</React.Fragment>
									</RichText>
								</motion.div>
							</motion.div>

							{/* 세 번째 행: 예약/캘린더(오른쪽) 및 안내 텍스트(왼쪽) */}
							<motion.div
								className={"framer-1anglia"}
								layoutDependency={layoutDependency}
								layoutId={"LWigqKB0k"}
							>
								{/* 좌측: 예약 안내 텍스트(제목 + 부제) */}
								<motion.div
									className={"framer-1gtqvae"}
									layoutDependency={layoutDependency}
									layoutId={"HSkI_zEya"}
								>
									<RichText
										__fromCanvasComponent={true}
										className={"framer-1utgwqa"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"q0M5A1ldy"}
										style={{
											"--extracted-2gg91v": '"opsz" 32, "wght" 700',
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOekF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv01' on, 'cv09' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "32px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 700)',
													"--framer-letter-spacing": "-0.03em",
													"--framer-line-height": "1em",
													"--framer-text-alignment": "left",
												}}
											>
												{"\uC608\uC57D \uD558\uAE30"}
											</motion.p>
										</React.Fragment>
									</RichText>
									<RichText
										__fromCanvasComponent={true}
										className={"framer-d1vh2b"}
										fonts={["Inter-Variable"]}
										layoutDependency={layoutDependency}
										layoutId={"vqqgeqAXc"}
										style={{
											"--extracted-2gg91v": '"opsz" 32, "wght" 500',
											"--extracted-r6o4lv": "rgb(153, 153, 153)",
											"--framer-link-text-color": "rgb(0, 153, 255)",
											"--framer-link-text-decoration": "underline",
										}}
										verticalAlignment={"top"}
										withExternalLayout={true}
									>
										<React.Fragment>
											{/* 예약 안내 문구(간단 클릭 유도용 텍스트) */}
											<motion.p
												style={{
													"--font-selector":
														"SW50ZXItVmFyaWFibGVWRj1JbTl3YzNvaUlETXlMQ0FpZDJkb2RDSWdOVEF3",
													"--framer-font-family":
														'"Inter Variable", "Inter Variable Placeholder", sans-serif',
													"--framer-font-open-type-features":
														"'cv09' on, 'cv01' on, 'cv05' on, 'ss03' on",
													"--framer-font-size": "22px",
													"--framer-font-variation-axes":
														'var(--extracted-2gg91v, "opsz" 32, "wght" 500)',
													"--framer-letter-spacing": "-0.01em",
													"--framer-text-alignment": "left",
													"--framer-text-color":
														"var(--extracted-r6o4lv, rgb(153, 153, 153))",
												}}
											>
												{"\uCE98\uB9B0\uB354\uB97C \uD074\uB9AD\uD558\uC138\uC694."}
											</motion.p>
										</React.Fragment>
									</RichText>
								</motion.div>

								{/* 우측: Cal.com 예약 위젯(외부 캘린더 임베드) */}
								<motion.div
									className={"framer-tcnzg2"}
									data-framer-name={"Placeholder"}
									layoutDependency={layoutDependency}
									layoutId={"BTFIUx1FZ"}
									style={{
										backgroundColor: "rgb(245, 245, 245)",
										borderBottomLeftRadius: 20,
										borderBottomRightRadius: 20,
										borderTopLeftRadius: 20,
										borderTopRightRadius: 20,
									}}
								>
									<motion.div
										className={"framer-1nigya7"}
										data-framer-name={"Placeholder"}
										layoutDependency={layoutDependency}
										layoutId={"pejhufWLR"}
										style={{
											backgroundColor: "rgb(245, 245, 245)",
											borderBottomLeftRadius: 20,
											borderBottomRightRadius: 20,
											borderTopLeftRadius: 20,
											borderTopRightRadius: 20,
										}}
									>
										<ComponentViewportProvider>
											<SmartComponentScopedContainer
												className={"framer-1dat20z-container"}
												isAuthoredByUser={true}
												isModuleExternal={true}
												layoutDependency={layoutDependency}
												layoutId={"jR6OV3AEJ-container"}
												nodeId={"jR6OV3AEJ"}
												rendersWithMotion={true}
												scopeId={"rARdbBz3O"}
											>
												{/* Calcom 위젯 삽입 (외부 예약 위젯) */}
												<Calcom
													darkTheme={"rgb(250, 250, 250)"}
													eventLink={
														"https://cal.com/framer-placeholder/default"
													}
													height={"100%"}
													id={"jR6OV3AEJ"}
													layout={"month_view"}
													layoutId={"jR6OV3AEJ"}
													lightTheme={"rgb(41, 41, 41)"}
													showEventTypeDetails={true}
													style={{
														height: "100%",
														width: "100%",
													}}
													theme={"auto"}
													width={"100%"}
												/>
											</SmartComponentScopedContainer>
										</ComponentViewportProvider>
									</motion.div>
								</motion.div>
							</motion.div>
						</motion.div>
					</motion.div>
				</Transition>
			</Variants>
		</LayoutGroup>
	);
});

/* -----------------------------
   컴포넌트 전용 CSS 문자열 배열 (withCSS로 주입)
   - serializationHash와 결합되어 컴포넌트 범위로 적용됩니다.
------------------------------ */
var css = [
	"@supports (aspect-ratio: 1) { body { --framer-aspect-ratio-supported: auto; } }",
	".framer-Ret0S.framer-zdprnl, .framer-Ret0S .framer-zdprnl { display: block; }",
	".framer-Ret0S.framer-1v99hk0 { height: 1659px; overflow: var(--overflow-clip-fallback, clip); position: relative; width: 1200px; }",
	".framer-Ret0S .framer-zra8u6-container { flex: none; height: auto; left: 50%; position: absolute; top: 0px; width: 100%; }",
	".framer-Ret0S .framer-ulorh8 { align-content: center; align-items: center; bottom: 0px; display: flex; flex: none; flex-direction: column; flex-wrap: nowrap; gap: 0px; height: min-content; justify-content: center; left: 50%; overflow: hidden; padding: 80px 20px 80px 20px; position: absolute; width: 100%; }",
	".framer-Ret0S .framer-csmpa3, .framer-Ret0S .framer-1anglia { align-content: center; align-items: center; display: flex; flex: none; flex-direction: row; flex-wrap: nowrap; gap: 0px; height: min-content; justify-content: center; max-width: 100%; overflow: hidden; padding: 0px; position: relative; width: 960px; }",
	".framer-Ret0S .framer-1dphzao { align-content: center; align-items: center; display: flex; flex: 1 0 0px; flex-direction: column; flex-wrap: nowrap; gap: 15px; height: min-content; justify-content: center; overflow: visible; padding: 0px; position: relative; width: 1px; }",
	".framer-Ret0S .framer-vormvr, .framer-Ret0S .framer-qbr9eh, .framer-Ret0S .framer-1utgwqa { flex: none; height: auto; max-width: 100%; position: relative; white-space: pre-wrap; width: 320px; word-break: break-word; word-wrap: break-word; }",
	".framer-Ret0S .framer-1hn1lh8 { --framer-text-wrap: balance; flex: none; height: auto; max-width: 100%; position: relative; white-space: pre-wrap; width: 372px; word-break: break-word; word-wrap: break-word; }",
	".framer-Ret0S .framer-1vleu1q, .framer-Ret0S .framer-tcnzg2, .framer-Ret0S .framer-1nigya7 { align-content: center; align-items: center; aspect-ratio: 1 / 1; display: flex; flex: 1 0 0px; flex-direction: row; flex-wrap: nowrap; gap: 10px; height: var(--framer-aspect-ratio-supported, 480px); justify-content: center; overflow: visible; padding: 0px; position: relative; width: 1px; }",
	".framer-Ret0S .framer-1ru02d7-container { bottom: 0px; flex: none; left: 0px; position: absolute; right: 0px; top: 0px; z-index: 1; }",
	".framer-Ret0S .framer-2lqcok, .framer-Ret0S .framer-teaxw2, .framer-Ret0S .framer-n22j9s { aspect-ratio: 1 / 1; height: var(--framer-aspect-ratio-supported, 960px); overflow: visible; position: relative; width: 960px; }",
	".framer-Ret0S .framer-uafayz { aspect-ratio: 1.497504159733777 / 1; height: var(--framer-aspect-ratio-supported, 451px); overflow: visible; position: relative; width: 675px; }",
	".framer-Ret0S .framer-fqb4qd { aspect-ratio: 1.3333333333333333 / 1; height: var(--framer-aspect-ratio-supported, 720px); overflow: visible; position: relative; width: 960px; }",
	".framer-Ret0S .framer-1z6ty7 { align-content: center; align-items: center; display: flex; flex: none; flex-direction: row; flex-wrap: nowrap; gap: 10px; height: min-content; justify-content: center; max-width: 100%; overflow: hidden; padding: 0px; position: relative; width: 960px; }",
	".framer-Ret0S .framer-qc1dan { align-content: center; align-items: center; aspect-ratio: 1 / 1; display: flex; flex: 1 0 0px; flex-direction: row; flex-wrap: nowrap; gap: 10px; height: var(--framer-aspect-ratio-supported, 475px); justify-content: center; overflow: visible; padding: 0px; position: relative; width: 1px; }",
	".framer-Ret0S .framer-16wjdxo-container { bottom: 0px; flex: none; left: 0px; position: absolute; right: -10px; top: 0px; z-index: 1; }",
	".framer-Ret0S .framer-2frul8, .framer-Ret0S .framer-1gtqvae { align-content: center; align-items: center; display: flex; flex: 1 0 0px; flex-direction: column; flex-wrap: nowrap; gap: 10px; height: min-content; justify-content: center; overflow: visible; padding: 0px; position: relative; width: 1px; }",
	".framer-Ret0S .framer-mt3197, .framer-Ret0S .framer-d1vh2b { --framer-text-wrap: balance; flex: none; height: auto; max-width: 100%; position: relative; white-space: pre-wrap; width: 320px; word-break: break-word; word-wrap: break-word; }",
	".framer-Ret0S .framer-1dat20z-container { flex: none; height: 480px; position: relative; width: 480px; }",
];

/* withCSS로 CSS를 컴포넌트에 바인딩하여 범위 한정 스타일 적용 */
var FramerrARdbBz3O = withCSS(Component, css, "framer-Ret0S");
var stdin_default2 = FramerrARdbBz3O;

/* 컴포넌트 메타: displayName 및 기본 크기(defaultProps) */
FramerrARdbBz3O.displayName = "cheong_ga";
FramerrARdbBz3O.defaultProps = {
	height: 1659,
	width: 1200,
};

/* Variable font의 variation axes 정보 (Inter variable 등에서 사용) */
var variationAxes = [
	{
		defaultValue: 14,
		maxValue: 32,
		minValue: 14,
		name: "Optical size",
		tag: "opsz",
	},
	{
		defaultValue: 400,
		maxValue: 900,
		minValue: 100,
		name: "Weight",
		tag: "wght",
	},
];

/* addFonts: 컴포넌트에서 사용할 폰트들을 등록(Inter variable + 서브컴포넌트 폰트 병합) */
addFonts(
	FramerrARdbBz3O,
	[
		{
			explicitInter: true,
			fonts: [
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange:
						"U+0460-052F, U+1C80-1C88, U+20B4, U+2DE0-2DFF, U+A640-A69F, U+FE2E-FE2F",
					url: "https://framerusercontent.com/assets/mYcqTSergLb16PdbJJQMl9ebYm4.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange: "U+0301, U+0400-045F, U+0490-0491, U+04B0-04B1, U+2116",
					url: "https://framerusercontent.com/assets/ZRl8AlxwsX1m7xS1eJCiSPbztg.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange: "U+1F00-1FFF",
					url: "https://framerusercontent.com/assets/nhSQpBRqFmXNUBY2p5SENQ8NplQ.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange: "U+0370-03FF",
					url: "https://framerusercontent.com/assets/DYHjxG0qXjopUuruoacfl5SA.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange:
						"U+0100-024F, U+0259, U+1E00-1EFF, U+2020, U+20A0-20AB, U+20AD-20CF, U+2113, U+2C60-2C7F, U+A720-A7FF",
					url: "https://framerusercontent.com/assets/s7NH6sl7w4NU984r5hcmo1tPSYo.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange:
						"U+0000-00FF, U+0131, U+0152-0153, U+02BB-02BC, U+02C6, U+02DA, U+02DC, U+2000-206F, U+2070, U+2074-207E, U+2080-208E, U+20AC, U+2122, U+2191, U+2193, U+2212, U+2215, U+FEFF, U+FFFD",
					url: "https://framerusercontent.com/assets/7lw0VWkeXrGYJT05oB3DsFy8BaY.woff2",
					variationAxes,
					weight: "400",
				},
				{
					cssFamilyName: "Inter Variable",
					source: "framer",
					style: "normal",
					uiFamilyName: "Inter",
					unicodeRange:
						"U+0102-0103, U+0110-0111, U+0128-0129, U+0168-0169, U+01A0-01A1, U+01AF-01B0, U+1EA0-1EF9, U+20AB",
					url: "https://framerusercontent.com/assets/wx5nfqEgOXnxuFaxB0Mn9OhmcZA.woff2",
					variationAxes,
					weight: "400",
				},
			],
		},
		...Navigation3Fonts,
		...SlideshowFonts,
		...GoogleMapsFonts,
		...CalComFonts,
	],
	{
		supportsExplicitInterCodegen: true,
	},
);

/* ----------------------------
   루트 컨텍스트로 감싸는 ComponentWithRoot 정의
   - ContextProviders로 routes, framerSiteId, locale 등을 제공
   - ComponentWithRoot.Responsive로 브레이크포인트별 variant 매핑 지원
----------------------------- */
// virtual:cheong-ga
import { WithFramerBreakpoints } from "unframer";
import { jsx } from "react/jsx-runtime";
var locales = [];
var defaultResponsiveVariants = {};

/** ContextProviders로 래핑된 기본 export 컴포넌트 */
function ComponentWithRoot({ locale, ...rest }) {
	return (
		<ContextProviders
			routes={routes}
			framerSiteId={
				"3759d569955c51a9b80f5c98b643a1993e0a03ee7b7b017caee5d6624b0e79fe"
			}
			locale={locale}
			locales={locales}
		>
			{jsx(stdin_default2, {
				...rest,
			})}
		</ContextProviders>
	);
}

/**
 * Responsive helper:
 * - WithFramerBreakpoints를 사용해 브레이크포인트별로 variant를 매핑하여 렌더링
 * - props로 variants 맵을 전달하면 브레이크포인트에 맞는 variant가 적용됩니다.
 */
ComponentWithRoot.Responsive = ({ locale = "", ...rest }) => {
	return (
		<ContextProviders
			routes={routes}
			framerSiteId={
				"3759d569955c51a9b80f5c98b643a1993e0a03ee7b7b017caee5d6624b0e79fe"
			}
			locale={locale}
			locales={locales}
		>
			<WithFramerBreakpoints
				Component={stdin_default2}
				variants={defaultResponsiveVariants}
				{...rest}
			/>
		</ContextProviders>
	);
};

/* ComponentWithRoot에 원본 컴포넌트의 정적 속성(예: displayName)을 병합 */
Object.assign(ComponentWithRoot, stdin_default2);

/* 기본 내보내기 */
var cheong_ga_default = ComponentWithRoot;
export { cheong_ga_default as default };
